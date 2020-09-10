#include "minishell_bonus.h"

int	main(void)
{
	t_vector	*vct_input;
	t_list		*lexer_list;
	int			ret;

	vct_input = vct_new();
//DEBUG1
	vct_addstr(vct_input, "Hello haha");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);
	
//DEBUG2
	vct_addstr(vct_input, "Hello |");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "hello|||>>haha|&&");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);
	
//DEBUG2
	vct_addstr(vct_input, "echo bonjour ; | . 2");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);


//DEBUG2
	vct_addstr(vct_input, "cat /dev/random | head -n 1 | cat -e .");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);


//DEBUG2
	vct_addstr(vct_input, "echo 2 >> out1 > out2 .");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);


//DEBUG2
	vct_addstr(vct_input, "echo $PATH");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG


//DEBUG2
	vct_addstr(vct_input, "echo hi; echo hihi;");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "echo ;;");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);


//DEBUG2
	vct_addstr(vct_input, "| echo");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);


//DEBUG2
	vct_addstr(vct_input, "echo | | echo");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);


//DEBUG2
	vct_addstr(vct_input, "cat < Makefile | grep gcc > output");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "cat < nofile | grep gcc > output // $? 1");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "var1=1+1");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "coucou==|& &&>>>");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "export TEST=LOL ; echo $TEST$TEST$TEST=lol$TEST");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "echo test > ls >> ls >> ls ; echo test >> ls; cat ls");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "echo \"bip | bip ; coyotte > < \" \" . bip | bip ; coyotte >< \"");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == 	TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "export var =\"cat Makefile | grep >\" .");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "echo hi \"   ;   \" hihi");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "grep christie /etc/passwd > /dev/null && echo \"L'utilisateur christie\"");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "test \"$var\" = \"Hello world !\"");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "test -e /etc/passwd && echo \"Le fichier existe\" || echo \"Le fichier n'existe pas\"");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "echo $@ \";exit\" | ./minishell 2>&");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "export TES=T="" ;");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "export TEST=\"ls       -l     - a\" ; echo $TEST ; $LS ; ");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "&& || | ||||| &&&&&& \";' haha\" \"$prout=hello\"=$HEY");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "ls > ls || hello && hello ; >> |");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == FALSE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, "");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

//DEBUG2
	vct_addstr(vct_input, ">> $HAHA = $haha");
	lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
	ret = parser_token(lexer_list); //fonction qui permet de voir si token fonctionne
	if (ret == TRUE)
		printf("\033[0;32mGOOD\n\033[0m");//DEBUG
	else
		printf("\033[0;31mFALSE\n\033[0m");//DEBUG
	vct_clear(vct_input);

































	free_list(&lexer_list);
	return (EXIT_SUCCESS);
}
