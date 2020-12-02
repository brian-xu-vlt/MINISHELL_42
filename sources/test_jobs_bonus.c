#include "minishell_bonus.h"

t_list	*test_jobs(t_list *lexer_list)
{
	t_list		*jobs;

	jobs = get_jobs(lexer_list);
	if (jobs == NULL)
		return (NULL);
	return (jobs);
}
