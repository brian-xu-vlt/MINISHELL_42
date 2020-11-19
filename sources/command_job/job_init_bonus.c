#include "minishell_bonus.h"

int		add_job_to_list(t_job *job, t_list **jobs, t_list *token_list,
							t_list **head)
{
	t_list	*node_job;

	node_job = ft_lstnew(job);
	if (node_job == NULL)
	{
		ft_lstdelone(node_job, NULL);
		free(node_job);
		print_set_errno(0, ERR_MALLOC, NULL, NULL);
		exit(FAILURE);
	}
	ft_lstadd_back(jobs, node_job);
	*head = token_list;
	return (SUCCESS);
}

t_job	*init_job(void)
{
	t_job	*job;

	job = (t_job *)malloc(sizeof(t_job));
	if (job == NULL)
	{
		print_set_errno(0, ERR_MALLOC, NULL, NULL);
		exit(FAILURE);
	}
	job->nb_cmd = 0;
	job->last_pid = 0;
	job->cmd_lst = NULL;
	return (job);
}
