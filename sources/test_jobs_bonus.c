#include "minishell_bonus.h"

void	debug_jobs(t_job *jobs)
{

}

t_job	*test_jobs(t_list *lexer_list)
{
	t_job		*jobs;
	
	jobs = get_jobs(lexer_list);
	if (jobs == NULL)
	{
		free_list_token(&lexer_list);
		return (NULL);
	}
	//debug_jobs(jobs);
	return (jobs);
}
