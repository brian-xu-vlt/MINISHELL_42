#! /bin/bash

print_separator(){
	i=1
	max=$(tput cols)
	while [ $i -le $max ]
	do
		echo -n $1
		((i+=1))
	done
	echo
}

print_diff_full () {
	echo -e "\e[31m \e[1m[  ] \e[0m\t\t["$TEST"]"
	#\t\t\t left is bash \t\t|\t\t right is minishell\n"
	colordiff -y /tmp/ba.err /tmp/minishell.err
}

print_diff_simple (){
	diff -s /tmp/ba.err /tmp/minishell.err &>/dev/null
	if [[ $? -ne 0 ]]
	then
		print_separator '▁'
		print_diff_full
		echo "🔴 $TEST" >> /tmp/test_ko
		print_separator '▔'
	else
		echo -e "\e[32m \e[1m[OK] \e[0m\t\t["$TEST"]"
	fi
}

test () {
	# export TEST=$(echo "$1")
	export TEST=$1
	echo "$TEST" | env -i ./Minishell 1>/tmp/minishell 2>/tmp/minishell.err #; echo "RETURNED : $?" >> /tmp/minishell.err
	echo "$TEST" | env -i bash --posix 1>/tmp/ba 2>/tmp/ba.err #; echo "RETURNED : $?" >> /tmp/ba.err
	cat /tmp/ba >> /tmp/ba.err
	cat /tmp/minishell >> /tmp/minishell.err
	echo -e "\n\n\t 🟡 [$TEST] 🟡 " >> /tmp/bash_sumup
	cat /tmp/ba.err >> /tmp/bash_sumup
	echo -e "\n\n\t 🟡 [$TEST] 🟡 " >> /tmp/minishell_sumup
	cat /tmp/minishell.err >> /tmp/minishell_sumup
	sed -i 's/NO_LINE_ED~$>//g' /tmp/minishell.err
	sed -i 's/Minishell: /bash: /g' /tmp/minishell.err
	sed -i 's/minishell: /bash: /g' /tmp/minishell.err
	sed -i 's/line [0-9]: //g' /tmp/ba.err
	print_diff_simple
	# print_diff_full
}


test_bonus () {
	print_separator '█'
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

test_correction_exec () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "/bin/ls"
	test "/bin/ip"
	test "/bin/aaaaaaaaaaaa"
	test "./non_existing_file______pouette"
	test "./fail_bin/segfault"
	test "non_existing_command______pouette"
	test "./Makefile"
	test "/dev"
	test "../../../ls"
	test "\"\""
	test ""
	test " "
}

test_correction_arg () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "/bin/ls -l"
	test "/bin/ls aaaaaaaaaaa"
	test "/bin/ls -x Makefile"
	test "/bin/ls - Makefile"
	test "/bin/ls -- Makefile"
}


test_correction_echo () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "echo echo echo echo"
	test "echo ; echo ; echo ; echo"
	test "echo coucou a b c d e f g"
	test "echo -n -n -n -n -n -n test"
	test "echo -n -n -N -n -n -n test"
	test "echo n -n -n -n -n -x test"
	test "echo - test"
}


test_correction_exit () {
	print_separator '█'
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


test_correction_return () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "/bin/ip ; echo \$?"
	test "/bin/ipaaaaaaaaaa ; echo \$?"
	test "/bin/ls aaaaaaabbbbbbbb ; echo \$?"
	test "/bin/ls aaaaaaaaaaa ; echo \$?"
	test "/bin/ls -x Makefile ; echo \$?"
	test "/bin/ls - Makefile ; echo \$?"
	test "/bin/ls -- Makefile ; echo \$?"
}


test_correction_semicolons () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "echo a ; echo b"
	test "echo a; echo b"
	test "echo a ;echo b"
	test "echo a;echo b"
	test "echo a' ; 'echo b"
	test "echo a'; 'echo b"
	test "echo a' ;'echo b"
	test "echo a';'echo b"
	test "echo a ';' echo b"
}


test_correction_baskslashs () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "ls \\Makefile"
	test "ls \\\"Makefile\\\""
	test "ls \\\'Makefile\\\'"
}


test_correction_env () {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "env | sort "
	test "export"
	test "unset"
	test "cat=meow ; env  | sort ; export"
	test "export cat ; env  | sort ; export"
	test "export cat=42 ; env  | sort ; export"

	test "cat=meow export food=pizza ; export ; export"
	test "cat=meow env; env | sort  ; export"
	test "cat=meow env; env | sort ; export"
	test "cat env; env | sort ; export"

	test "export -toto=1"
	test "export cat=meow ; echo \$cat"
	test "food=pizza export; export"
	test "unset hfdjskhdfkjhfsd ; env | sort"
	test "export cat ; unset cat ; export"
	test "export cat=meow ; unset cat ; export"
	test "export cat=meow ; export cat=woof ; export"
	test "export cat=meow ; cat=woof ; export"
	test "cat=meow ; export cat=woof ; export"
	test "cat=meow ; export cat=woof export ; export"
	test "cat+=woof ; cat+=woof ; cat+=piaou ; export cat; export"
	test "export cat=woof ; cat+=woof ; cat+=piaou ; export"
	test "export cat+=woof ; cat+=woof ; cat+=piaou ; export"
	test "export ERR+EUR=1"
	test "export VAR-INVALID=1"
	test "export PATH=42 ; export"
	test "export ; export"
	test "cat=moew export | export"
	test "export cat=moew | export"
	test "cat=moew export"
	test "export cat=moew"
	test "unset PATH ; export PATH ; export"

}

test_correction_exp () {
	print_separator '█'

	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"
	test "echo \$TERM"
	test "echo \$\"TERM\""
	test "echo \$\'TERM\'"
	test "echo \$TERM\$PWD"
	test "echo \$TERMaaaaaaa"
	test "echo aaaaaaa\$TERM"
	test "echo -\$TERM"
	test "cmd=\"ls\" ; \$cmd"
}

test_correction_cd() {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "cd ../ ; /bin/ls"
	test "cd ../././../// ; /bin/ls"
	test "cd / ; /bin/ls"
	test "cd ./ ; /bin/ls"
	test "cd ./.. ; /bin/ls"
	test "cd ./sources ; /bin/ls"
	test "cd ./aaaaaaaaaa ; /bin/ls"
	test "cd aaaaaaa ; /bin/ls"
	test "rm -rf /tmp/aaa ; mkdir -p /tmp/aaa ; cd /tmp/aaa ; /bin/ls"
	test "rm -rf /tmp/aaa ; mkdir -p /tmp/aaa ; chmod 000 /tmp/aaa ; cd /tmp/aaa ; /bin/ls"
	test "rm -rf /tmp/aaa ; mkdir -p /tmp/aaa ; cd /tmp/aaa ; rm -rf /tmp/aaa ; cd .. ; /bin/ls"
	test "cd /tmp ; cd - ; /bin/ls"
	test "cd Makefile"
	test "cd -x"
}

test_correction_pwd() {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "pwd"
	test "pwd -X"
	test "pwd aaaaaaaaa"
	test "pwd ./aaaaaaaaa"
	test "cd ../ ; pwd"
	test "cd ../././../// ; pwd"
	test "cd / ; pwd"
	test "cd ./ ; pwd"
	test "cd ./ ; pwd"
	test "cd ./sources ; pwd"
	test "cd ./aaaaaaaaaa ; pwd"
	test "cd aaaaaaa ; pwd"
	test "rm -rf /tmp/aaa ; mkdir -p /tmp/aaa ; cd /tmp/aaa ; pwd"
	test "rm -rf /tmp/aaa ; mkdir -p /tmp/aaa ; cd /tmp/aaa ; chmod 000 /tmp/aaa ; pwd"
	test "rm -rf /tmp/aaa ; mkdir -p /tmp/aaa/bbb ; cd /tmp/aaa/bbb ; rm -rf /tmp/aaa ; pwd"
	test "cd /tmp ; cd - ; pwd"
}

test_correction_PATH() {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "unset PATH; \"\""
	test "unset PATH; hjsdfkhfds"
	test "unset PATH; ls"
	test "unset PATH; Makefile"
	test "unset PATH; /bin/ls"
	test "export PATH=\"\"; ls"
	test "export PATH= ; ls"
	test "export PATH=pizza ; ls"
	test "export PATH=pizza ; pwd"
	test "export PATH=pizza ; echo"
	test "PATH=/tmp:./ ; ls"
}

test_correction_simple_quotes(){
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "ls ''"
	test "ls ''''"
	test "echo ''"
	test "echo $''"
	test "export toto='' ; export"
	test "''"
	test "cat ''"
}

test_correction_redirect(){
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "ls /dev > /tmp/file ; cat /tmp/file"
	test "cal >/dev"
	test "cal >"
	test "date >../../../../../../../../../../../../tmp/file2 ; cat /tmp/file2"
	test "ls /tmp > /tmp/ls ; cat </tmp/ls"
	test "ls > /tmp/ls ; pwd >> /tmp/ls ; cat </tmp/ls"
	test "cat < /tmp/ls ; cat /tmp/ls"
	test "cat </dev"
	test "cat >/dev"
	test "touch /tmp/aaaaaaaa >/dev ; ls /tmp/aaaaaaaaa"
	test "touch /tmp/aaaaaaaa </dev ; ls /tmp/aaaaaaaaa"
	test "rm -rf /tmp/b ; ls >> /tmp/b ; ls >> /tmp/b ; ls >> /tmp/b ; ls >> /tmp/b ; cat /tmp/b"
	test "rm -rf /tmp/b ; ls >> /tmp/b ; ls >> /tmp/b ; ls >> /tmp/b ; ls > /tmp/b ; cat /tmp/b"
	test "cp Makefile /tmp/b ; true > /tmp/b ; cat </tmp/b"
	test "cat > coucou > test_cat < coucou | cat < coucou ; rm -rf coucou test_cat"
	test "rm -rf /tmp/a ; ls >/tmp/a </dev ; ls /tmp/a"
	test "rm -rf /tmp/a ; touch /tmp/a >>/dev ; ls /tmp/a"
	test "rm -rf /tmp/a ; touch /tmp/a >/dev ; ls /tmp/a"
}

test_correction_pipes() {

	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "ls | sort | cut -b 1-6"
	test "ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls"
	test "ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |aaaaaaaaaaaa |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls |ls"
	test "true | false | true"
	test "false | false | true"
	test "cat | cat | cat | grep 42"
	test "rm -rf /tmp/a /tmp/b ; touch /tmp/a | ls >/dev | touch /tmp/b ; ls /tmp/a /tmp/b"

}

test_signal() {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	# test "
	#  	fail_bin/buserror;
	#  	fail_bin/abort;
	#  	fail_bin/segfault;
	#  "
}

test_random() {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "1"
	test "1 2 3 4 5 6 7 8 9"
	test "-1 -2"
	test "\\\n"
	test ";"
	test "|"
	test ";|"
	test ">>"
	test "<"
	test ">"
	test ";>>|><"
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
		toto+=42; echo \$toto
	"
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
	test "4ABC=toto"
}

test_failed() {
	print_separator '█'
	echo -e "\n\n\e[34m \e[1m[$FUNCNAME] \e[0m"

	test "	\"e\"'c'ho 'b'\"o\"nj\"o\"'u'r\";\"	"
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
		echo
		# test_random
		# test_bonus
		# test_executor
		# test_failed
		# test_signal

		# test_correction_exec
		# test_correction_arg
		# test_correction_echo
		# test_correction_exit
		# test_correction_return
		# test_correction_semicolons
		# test_correction_baskslashs
		# test_correction_env
		# test_correction_exp
		# test_correction_cd
		# test_correction_pwd
		# test_correction_PATH
		test_correction_simple_quotes
		test_correction_redirect
		test_correction_pipes
	fi

	FAILED_TEST=$(cat /tmp/test_ko | wc -l)
	if [[ $FAILED_TEST -gt 0 ]]
	then
		echo -e "\n\n\e[31m \e[1m[ $(cat /tmp/test_ko | wc -l) FAILED TEST] \e[0m"
		cat /tmp/test_ko
	fi
}

main "$1"
