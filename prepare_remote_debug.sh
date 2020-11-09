#! /bin/bash

# Kill gdbserver if it's running
ssh user42@papy killall gdbserver &> /dev/null

# Compile myprogram and launch gdbserver, listening on port 9091
ssh                         \
  -L9091:localhost:9091     \
  user42@papy               \
  "zsh -l -c 'cd /home/user42/42/minishell/REPO && make debug_mode=1 debug=0 err=1 opti=0 CC=clang -j8 && gdbserver :9091 ./Minishell'"
