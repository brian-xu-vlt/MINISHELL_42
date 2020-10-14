#include "minishell_bonus.h"

t_list	*test_lexer(t_vector *input)
{
	t_list		*lexer_list;
	
//	ft_printf("\n%s\n", vct_getstr(input));
	lexer_list = lexer(input);
	if (lexer_list == NULL)
	{
		ft_printf("\033[31;01m[!] ERROR LEXER [!]\033[00m\n\n");
		return (NULL);
	}
	return (lexer_list);
}
