#include "minishell_bonus.h"

t_list	*test_lexer(t_vector *input)
{
	t_list		*lexer_list;
	
//	ft_printf("\n%s\n", vct_getstr(input));
	lexer_list = lexer(input);
	if (lexer_list == NULL)
	{
		free_list_token(&lexer_list);
		return (NULL);
	}
	return (lexer_list);
}
