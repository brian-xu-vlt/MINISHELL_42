#include "minishell_bonus.h"

/*static void	debug_jobs(t_list *jobs)
{
	while (jobs != NULL)
	{
		ft_printf("JOBS\n");//DEBUG
	}
}*/

int	test(t_vector *input)
{
	t_list		*lexer_list;
	t_list		*jobs;

	lexer_list = NULL;
	ft_printf("\n%s\n", vct_getstr(input));
	lexer_list = lexer(input);
	if (lexer_list == NULL)
	{
		free_list_token(&lexer_list);
		//vct_del(&input);
		return (FAILURE);
	}
	if (parser_token(lexer_list) == FALSE)
	{
		free_list_token(&lexer_list);
		//vct_del(&input);
		return (FAILURE);
	}
	/*jobs = get_jobs(lexer_list);
	if (jobs == NULL)
	{
		free_list_token(&lexer_list);
		return (FAILURE);
	}*/	
	//debug_jobs(jobs);
	free_list_token(&lexer_list);
	return (SUCCESS);
}
