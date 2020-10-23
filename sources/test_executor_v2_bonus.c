#include "minishell_bonus.h"

int		test_executor_v2(t_list *jobs)
{
	if (jobs == NULL)
		return (FAILURE);
	while (jobs != NULL)
	{
		if (jobs->content != NULL)
			executor(jobs->content);
		jobs = jobs->next;
		
	}
	return (SUCCESS);
}
