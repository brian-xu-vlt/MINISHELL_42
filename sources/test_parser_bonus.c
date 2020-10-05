#include "minishell_bonus.h"

int	test_parser(t_list *lexer_list)
{
	if (parser_token(lexer_list) == FALSE)
	{
		ft_printf("\033[31;01m[!] ERROR PARSER [!]\033[00m\n\n");
		return (FALSE);
	}
	return (SUCCESS);
}
