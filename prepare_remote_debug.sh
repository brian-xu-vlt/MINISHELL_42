#! /bin/bash

# Kill gdbserver if it's running
ssh user42@papy killall gdbserver &> /dev/null

# Compile myprogram and launch gdbserver, listening on port 9091
ssh                         \
  -L9091:localhost:9091     \
  user42@papy               \
  "zsh -l -c 'echo $TERM ; cd /home/user42/42/minishell/REPO && make debug=0 err=1 CC=clang -j8 && gdbserver :9091 ./Minishell'"
