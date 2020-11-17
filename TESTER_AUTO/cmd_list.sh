#! /bin/bash

print_separator(){
	i=1
	max=$(tput cols)
	while [ $i -le $max ]
	do
		echo -n '▁'
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
	diff -s /tmp/ba /tmp/minishell &>/dev/null
	if [[ $? -ne 0 ]]
	then
		echo -e "\e[31m \e[1m["$TEST"]\e[0m\t\t\t left is bash \t\t|\t\t right is minishell\n"
		colordiff -y /tmp/ba /tmp/minishell
	else
		echo -e "\e[32m \e[1m[OK] \e[0m\t\t["$TEST"]"
	fi
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
	test "
		toto+=42; echo \$toto ;
		toto+=.; echo \$toto ;
		toto+=-; echo \$toto ;
		toto+='' ; echo \$toto ;
		toto+=42; echo \$toto ;
		toto+=42; echo \$toto ;
		toto+=42; echo \$toto ;
		toto+=42; echo \$toto ;		"
	test "echo -n -n -n -n -n -n test"
	test "echo -n -n -x -n -n -n test"
	test "echo -n -n -n -n -n -x test"
	test "echo > /tmp/test"
	test "cat -e /tmp/test"
	test "echo -n > /tmp/test"
	test "cat -e /tmp/test"
	test "echo \$?"
	test "ls hdfjkdsf ; echo \$?"
	test "ls hdfjkdsf ; echo \$?"
	test "
	\"e\"'c'ho 'b'\"o\"nj\"o\"'u'r\";\"
	"
	# test "exit 5"
	# test "exit abcdef"
	# test "exit 2 2 2 2 2 2"
	# test "exit dqdsqd 2 dsqdqs"
	# test "exit 9223372036854775807"
	# test "exit 9223372036854775808"
	# test "exit 500"
	# test "exit -500"




fi
