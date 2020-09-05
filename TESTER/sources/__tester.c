#include "tester.h"

t_lex	g_lexer = lexer;

int		main()
{
	tester("hello|||>>haha|&&", "WORD:hello-||-|->>-WORD:haha-|-&&");
	tester("hello=wejfh=", "=:hello=wejfh=");
	tester("$hellowejfh", "$:$hellowejfh");
	return (EXIT_SUCCESS);
}
