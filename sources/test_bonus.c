#include "minishell_bonus.h"

int	test(t_vector *input)
{
	t_list		*lexer_list;
	t_list		*jobs;

	lexer_list = NULL;
	ft_printf("\n%s\n", vct_getstr(input));
	lexer_list = lexer(input);
	if (lexer_list == NULL)
	{
		free_list(&lexer_list);
		//vct_del(&input);
		return (FAILURE);
	}
	if (parser_token(lexer_list) == FALSE)
	{
		free_list(&lexer_list);
		//vct_del(&input);
		return (FAILURE);
	}
	if (get_jobs(lexer_list, input) == NULL)
	{
		free_list(&lexer_list);
		return (FAILURE);
	}	
	free_list(&lexer_list);
	return (SUCCESS);
}

