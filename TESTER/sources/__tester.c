#include "tester.h"

t_lex	g_lexer = lexer;

int		main()
{
	tester("hello|||>>haha|&&", "WORD@hello#||#|#>>#WORD@haha#|#&&");
	tester("hello=wejfh=", "=@hello=wejfh=");
	tester("$hellowejfh", "$@$hellowejfh");
	tester("$hellowejfh", "$@$hellowejfh");
	tester("echo bonjour ; | . 2", "WORD@echo#WORD@bonjour#;#|#WORD@.#WORD@2");
	tester("echo bonjour | | . 2", "WORD@echo#WORD@bonjour#|#|#WORD@.#WORD@2");
	tester("echo bonjour ; ls . bonjour ; ls", "WORD@echo#WORD@bonjour#;#WORD@ls#WORD@.#WORD@bonjour#;#WORD@ls");
	tester("cd $HOME/Bureau .", "WORD@cd#$@$HOME/Bureau#WORD@.");
	tester("cat /dev/random | head -n 1 | cat -e .", "WORD@cat#WORD@/dev/random#|#WORD@head#WORD@-n#WORD@1#|#WORD@cat#WORD@-e#WORD@.");
	tester("cat Makefile | grep pr | head -n 5 | cd test (mybin) . 1", "WORD@cat#WORD@Makefile#|#WORD@grep#WORD@pr#|#WORD@head#WORD@-n#WORD@5#|#WORD@cd#WORD@test#WORD@(mybin)#WORD@.#WORD@1");
	tester("echo bonjour >>> test .", "WORD@echo#WORD@bonjour#>>#>#WORD@test#WORD@.");
	tester("echo 2 >> out1 > out2 .", "WORD@echo#WORD@2#>>#WORD@out1#>#WORD@out2#WORD@.");
	tester("echo 2 > out1 >> out2 .", "WORD@echo#WORD@2#>#WORD@out1#>>#WORD@out2#WORD@.");
	tester(" cat < test .", "WORD@cat#<#WORD@test#WORD@.");
	tester("cd ../../../../../.. . pwd . /", "WORD@cd#WORD@../../../../../..#WORD@.#WORD@pwd#WORD@.#WORD@/");
	tester("echo \"bip | bip ; coyotte > < \" \" . bip | bip ; coyotte >< \"", "WORD@echo#\"#WORD@bip#|#WORD@bip#;#WORD@coyotte#>#<#\"#\"#WORD@.#WORD@bip#|#WORD@bip#;#WORD@coyotte#>#<#\"");
	tester("export var =\"cat Makefile | grep >\" . ", "WORD@export#WORD@var#WORD@=#\"#WORD@cat#WORD@Makefile#|#WORD@grep#>#\"#WORD@.");
	tester("export \"test=ici\"=coucou . test=ici=coucou", "WORD@export#\"#=@test=ici#\"#WORD@=coucou#WORD@.#=@test=ici=coucou");
	tester("c$var Makefile (avec $var=at) .", "$@c$var#WORD@Makefile#WORD@(avec#=@$var=at)#WORD@.");
	tester("$LESS$VAR .", "$@$LESS$VAR#WORD@.");
	tester("echo bonjour > $test w/ t", "WORD@echo#WORD@bonjour#>#$@$test#WORD@w/#WORD@t");
	tester("echo $PATH", "WORD@echo#$@$PATH");
	tester("echo \"$PATH\"", "WORD@echo#\"#$@$PATH#\"");
	tester("echo hi; echo hihi;", "WORD@echo#WORD@hi#;#WORD@echo#WORD@hihi#;");
	tester("echo ;;", "WORD@echo#;#;");
	tester("echo hi\";\" hihi", "WORD@echo#WORD@hi#\"#;#\"#WORD@hihi");
	tester("echo hi \"   ;   \" hihi", "WORD@echo#WORD@hi#\"#;#\"#WORD@hihi");
	tester("echo one; echo two; echo three;", "WORD@echo#WORD@one#;#WORD@echo#WORD@two#;#WORD@echo#WORD@three#;#");
	tester("export LOL=lol", "WORD@export#=@LOL=lol");
	tester("export LOL=lala ROR=rara", "WORD@export#=@LOL=lala#=@ROR=rara");
	tester("export \"HI= hi\"", "WORD@export#\"#WORD@HI=#WORD@hi#\"#");
	tester("export \"HI =hi\"", "WORD@export#\"#WORD@HI#WORD@=hi#\"");
	tester("echo $?", "WORD@echo#$@$?");
	tester("| echo", "|#WORD@echo");
	tester("echo |", "WORD@echo#|");
	tester("echo | | echo", "WORD@echo#|#|#WORD@echo");
	tester("cat < Makefile | grep gcc > output", "WORD@cat#<#WORD@Makefile#|#WORD@grep#WORD@gcc#>#WORD@output");
	tester("cat < nofile | grep gcc > output // $? 1", "WORD@cat#<#WORD@nofile#|#WORD@grep#WORD@gcc#>#WORD@output#WORD@//#$@$?#WORD@1");
	tester("if grep christie /etc/passwd > /dev/null  > then ", "WORD@if#WORD@grep#WORD@christie#WORD@/etc/passwd#>#WORD@/dev/null#>#WORD@then");
	tester("grep christie /etc/passwd > /dev/null && echo \"L'utilisateur christie", "WORD@grep#WORD@christie#WORD@/etc/passwd#>#WORD@/dev/null#&&#WORD@echo#\"#WORD@L#'#WORD@utilisateur#WORD@christie");
	tester("test [-z|-n] $variable", "WORD@test#WORD@[-z#|#WORD@-n]#$@$variable");
	tester("test \"$var\" = \"Hello world !\"", "WORD@test#\"#$@$var#\"#WORD@=#\"#WORD@Hello#WORD@world#WORD@!#\"");
	tester("test \"num1\" [-eq|-ne|-gt|-lt] \"num2\"", "WORD@test#\"#WORD@num1#\"#WORD@[-eq#|#WORD@-ne#|#WORD@-gt#|#WORD@-lt]#\"#WORD@num2#\"");
	tester("test \"$var\" -eq \"1\"", "WORD@test#\"#$@$var#\"#WORD@-eq#\"#WORD@1#\"");
	tester("test \"1\" = \"1\"", "WORD@test#\"#WORD@1#\"#WORD@=#\"#WORD@1#\"");
	tester("var1=1+1", "=@var1=1+1");
	tester("let $var1", "WORD@let#$@$var1");
	tester("var=$((5*3))", "=@var=$((5*3))");
	tester("test -e /etc/passwd && echo \"Le fichier existe\" || echo \"Le fichier n'existe pas\"", "WORD@test#WORD@-e#WORD@/etc/passwd#&&#WORD@echo#\"#WORD@Le#WORD@fichier#WORD@existe#\"#||#WORD@echo#\"#WORD@Le#WORD@fichier#WORD@n#'#WORD@existe#WORD@pas#\"");
	return (EXIT_SUCCESS);
}
