#include "minishell_bonus.h"

int	test_parser(t_list *lexer_list)
{
	if (parser_token(lexer_list) == FALSE)
		return (FALSE);
	return (TRUE);
}
