#include "minishell_bonus.h"

int	tester(char *string, int expected)
{
	int			ret;
	t_list		*lexer_list;
	t_vector	*vct_input;

	vct_input = vct_new();
	vct_addstr(vct_input, string);
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	
	printf("[%s]%-*s\t=>\t", string, (int)(80 - ft_strlen(string)), "");//DEBUG
	if (ret == expected)
		printf("\033[0;32mOK\t\033[0m");//DEBUG
	else
		printf("\033[0;31mKO\t\033[0m");//DEBUG
	printf("('%-5s' expected)\n\n", expected == TRUE ? "TRUE" : "FALSE");//DEBUG
	vct_del(&vct_input);
	free_list_token(&lexer_list);
	return (ret);
}

int	main(void)
{
	// TRUE
	tester("Hello haha", TRUE);
	tester("cat /dev/random | head -n 1 | cat -e .", TRUE);
	tester("echo 2 >> out1 > out2 .", TRUE);
	tester("echo $PATH", TRUE);
	tester("echo hi; echo hihi;", TRUE);
	tester("cat < Makefile | grep gcc > output", TRUE);
	tester("cat < nofile | grep gcc > output // $? 1", TRUE);
	tester("var1=1+1", TRUE);
	tester("export TEST=LOL ; echo $TEST$TEST$TEST=lol$TEST", TRUE);
	tester("echo test > ls >> ls >> ls ; echo test >> ls; cat ls", TRUE);
	tester("echo \"bip | bip ; coyotte > < \" \" . bip | bip ; coyotte >< \"", TRUE);
	tester("export var =\"cat Makefile | grep >\" .", TRUE);
	tester("echo hi \"   ;   \" hihi", TRUE);
	tester("grep christie /etc/passwd > /dev/null && echo \"L'utilisateur christie\"", TRUE);
	tester("test \"$var\" = \"Hello world !\"", TRUE);
	tester("test -e /etc/passwd && echo \"Le fichier existe\" || echo \"Le fichier n'existe pas\"", TRUE);
	tester("echo $@ \";exit\" | ./minishell 2>&", TRUE);
	tester("export TES=T="" ;", TRUE);
	tester("export TEST=\"ls       -l     - a\" ; echo $TEST ; $LS ; ", TRUE);
	tester("", TRUE);
	tester(">> $HAHA = $haha", TRUE);


	// FALSE
	tester("echo ;;", FALSE);
	tester("&& || | ||||| &&&&&& \";' haha\" \"$prout=hello\"=$HEY", FALSE);
	tester("ls > ls || hello && hello ; >> |", FALSE);
	tester("coucou==|& &&>>>", FALSE);
	tester("| echo", FALSE);
	tester("echo | | echo", FALSE);
	tester("Hello |", FALSE);
	tester("hello|||>>haha|&&", FALSE);
	tester("echo bonjour ; | . 2", FALSE);

	return (EXIT_SUCCESS);
}
