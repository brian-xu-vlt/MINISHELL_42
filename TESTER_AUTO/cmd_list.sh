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
	echo "$TEST" | ./Minishell 1>/tmp/minishell 2>/tmp/minishell.err
	sed -i 's/NO_LINE_ED~$>//g' /tmp/minishell
	echo "$TEST" | bash --posix 1>/tmp/ba 2>/tmp/ba.err
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
	test "ls -l"
	test "food=pizza export; export"
	test "export cat=meow ; echo \$cat"
	test "export cat=meow ; env | sort"
	test "unset hfdjskhdfkjhfsd ; env | sort"
	test "hfdjskhdfkjhfsd"
	test "ls fdsfsdfhfsd"
	test "echo aaaaa bbbb cccccc dddddd > /tmp/a ; cat -e /tmp/a"
	test "echo terminal is [\$TERM]"
	test "echo terminal is [\$TERM4"
fi
