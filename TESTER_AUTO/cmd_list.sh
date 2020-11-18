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

print_diff_full () {
	echo -e "\e[31m \e[1m["$TEST"]\e[0m\t\t\t left is bash \t\t|\t\t right is minishell\n"
	colordiff -y /tmp/ba /tmp/minishell
}

print_diff_simple (){
	diff -s /tmp/ba /tmp/minishell &>/dev/null
	if [[ $? -ne 0 ]]
	then
		print_diff_full
		echo "🔴 $TEST" >> /tmp/test_ko
	else
		echo -e "\e[32m \e[1m[OK] \e[0m\t\t["$TEST"]"
	fi
}

test () {
	export TEST=$(echo "$1")
	echo "$TEST" | env -i ./Minishell 1>/tmp/minishell 2>/tmp/minishell.err
	echo "$TEST" | env -i bash --posix 1>/tmp/ba 2>/tmp/ba.err
	cat /tmp/ba.err >> /tmp/ba
	cat /tmp/minishell.err >> /tmp/minishell
	cat /tmp/ba >> /tmp/bash_sumup
	cat /tmp/minishell >> /tmp/minishell_sumup
	sed -i 's/NO_LINE_ED~$>//g' /tmp/minishell
	sed -i 's/Minishell: /bash: /g' /tmp/minishell
	sed -i 's/line [0-9]: //g' /tmp/ba
	print_separator
	print_diff_simple
	# print_diff_full
}


test_bonus () {
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "\"\""
	test "\'\'"
	test "echo a && echo b ; echo \$?"
	test "echo a || echo b ; echo \$?"
	test "false || echo b ; echo \$?"
	test "false && echo b ; echo \$?"
	test "echo a || false ; echo \$?"
	test "echo a && false ; echo \$?"
}

test_correction () {
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "/bin/ls"
	test "/bin/ls -l"
	test "echo echo echo echo"
	test "echo ; echo ; echo ; echo"
	test "/bin/ip ; echo \$?"
	test "/bin/ipee ; echo \$?"
	test "/bin/ls non_existingfileeee ; echo \$?"

}

test_executor() {
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "./non_existing_file______pouette"
	test "./fail_bin/segfault"
	test "non_existing_command______pouette"
	test "./Makefile"
	test "/dev"
	test "../../../ls"
	test "\"\""
	test ""
	test "unset PATH; \"\""
	test "unset PATH; hjsdfkhfds"
	test "unset PATH; ls"
	test "unset PATH; Makefile"
	test "unset PATH; /bin/ls"
	test "unset PATH; /bin/ls"
	# test "
	#  	fail_bin/buserror;
	#  	fail_bin/abort;
	#  	fail_bin/segfault;
	#  "
}

test_exit () {
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "exit 5"
	test "exit abcdef"
	test "exit 2 2 2 2 2 2"
	test "exit dqdsqd 2 dsqdqs"
	test "exit 9223372036854775807"
	test "exit 9223372036854775808"
	test "exit 500"
	test "exit -500"
}

test_random () {
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "ls -l"
	test "export cat=meow ; echo \$cat"
	test "unset SHSLVL PATH PWD OLDPWD _ ; echo \$PWD ; pwd ; ls"
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
	test "export TEST; export | grep TEST"
	test "export TEST=1; export | grep TEST"
	test "export VAR_VALID=1"
	test "export BROK;EN_VAR=1; export | grep EN_VAR"
	test "export TEST+=23; export | grep TEST"
	test "export TEST1 TEST2=456 TEST4 TEST5 TEST3=78"
	test "
	export TEST1=123; export TEST1 TEST2=456 TEST4 TEST5 TEST3=789		;
	echo \$TEST\$TEST2\$TEST3 > /tmp/test1 > /tmp/test2 > /tmp/test3	;
	cat /tmp/test1; cat /tmp/test2; cat /tmp/test3
	"
	test "cd .././../.././../bin/ls"
	test "unset \$HOME; cd"
	test "touch /tmp/file ; /tmp/file"
	test "cat > coucou > test_cat < coucou | cat < coucou ; rm coucou test_cat"
	test "4ABC=toto"
}

test_failed () {
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "food=pizza export; export"
	test "export cat=meow ; env | sort"
	test "unset hfdjskhdfkjhfsd ; env | sort"
	test "	\"e\"'c'ho 'b'\"o\"nj\"o\"'u'r\";\"	"
	test "export ERR+EUR=1"
	test "export VAR-INVALID=1"
	test "
		export EMPTY ;
		export NOTEMPTY= ;
		export CHARS=AAA ;
		echo '\$CHARS' ;
		echo \$CHARS ;
		echo \$PWD\$HOMe\"\$VAR_NONEXISTANT\$PWD\" \$NOTEMPTY\$EMPTY'' \$\"VAR_NONEXISTANT\"'\$EMPTY\$\"PWD' \$CHARS\"\$CHARS\"'\$PWD\"\$PWD\"'\$EMPTY\$NOTEMPTY |wc -m ;
	"
	test "
		export EMPTY ;
		export NOTEMPTY= ;
		export CHARS=AAA ;
		echo '\$CHARS' ;
		echo \$CHARS ;
		echo \$PWD\$VAR_NONEXISTANT\"\$VAR_NONEXISTANT\$PWD\" \$NOTEMPTY\$EMPTY'' \$\"VAR_NONEXISTANT\"'\$EMPTY\$\"PWD' \$CHARS\"\$CHARS\"'\$PWD\"\$PWD\"'\$EMPTY\$NOTEMPTY ;
	"
	test "
		echo \"\$HOME\"
		echo \$HOME
		echo \"\$\"HOME
		echo \$\"\"HOME
		echo \"\"\$HOME
		echo \$\"HOME\"
		echo \$\"HO\"\"ME\"
		echo \"\$HO\"\"ME\"
		echo \"\$HO\"ME
		echo \$\"HOME\"
	"
	test "
		mkdir -p test1/test2/test3
		cd test1/test2/test3
		rm -r ../../../test1
		cd ..
		pwd
		cd ..
		pwd
		cd ..
		pwd
	"
	test "export 4ABC=toto"
	test "toto/tata=1"



}

main () {
	true > /tmp/test_ko
	true > /tmp/minishell_sumup
	true > /tmp/bash_sumup
	if [[ -n "$1" ]]
	then
		test "$1"
	else
		# test_random
		# test_bonus
		# test_exit
		test_executor
		test_correction
		# test_failed
	fi
	echo -e "\n\n\e[31m \e[1m[ALL FAILED TEST] \e[0m"
	cat /tmp/test_ko
}

main $1
