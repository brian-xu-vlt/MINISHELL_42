#! /bin/bash

print_separator(){
	i=1
	max=$(tput cols)
	while [ $i -le $max ]
	do
		echo -n '█'
		((i+=1))
	done
	echo
}

test () {
	TEST=$(echo "$1")
	./Minishell 1>/tmp/minishell 2>/tmp/minishell.err & kill -s $TEST $(pgrep Minishell)
	sed -i 's/NO_LINE_ED~$>//g' /tmp/minishell
	bash --posix 1>/tmp/ba 2>/tmp/ba.err & kill -s $TEST $(pgrep bash)
	cat /tmp/ba.err >> /tmp/ba
	cat /tmp/minishell.err >> /tmp/minishell
	print_separator
	echo -e "\e[33m \e[1m["$TEST"]\e[0m\t\t\t left is bash \t\t|\t\t right is minishell\n"
	colordiff -y /tmp/ba /tmp/minishell
	echo
}

if [[ -n "$1" ]]
then
	test "$1"
else
	# test "SIG16"
	# test "SIGALRM"
	# test "SIGCONT"
	# test "SIGILL"
	# test "SIGPIPE"
	test "SIGQUIT"
	# test "SIGSYS"
	# test "SIGTSTP"
	# test "SIGURG"
	# test "SIGVTALRM"
	# test "SIGXFSZ"
	# test "SIG30"
	test "SIGBUS"
	# test "SIGFPE"
	# test "SIGINT"
	# test "SIGPOLL"
	test "SIGSEGV"
	test "SIGTERM"
	# test "SIGTTIN"
	# test "SIGUSR1"
	# test "SIGWINCH"
	# test "SIGABRT"
	# test "SIGCHLD"
	# test "SIGHUP"
	# test "SIGKILL"
	# test "SIGPROF"
	# test "SIGSTOP"
	# test "SIGTRAP"
	# test "SIGTTOU"
	# test "SIGUSR2"
	# test "SIGXCPU"
fi


#i=0 ; while [ $i -le 5 ]; do; ./Minishell ; ((i+=1)); done
#kill -s SIGBUS $(pgrep -f Minishell)
