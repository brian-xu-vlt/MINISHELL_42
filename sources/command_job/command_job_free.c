#include "minishell_bonus.h"


static void	del_cmd(void *data)
{
	const t_cmd *cmd = (t_cmd *)data;
	int		i;

	if (cmd == NULL)
		return ;
	free(cmd->name);
	free(cmd->fd_string[0]);
	free(cmd->fd_string[1]);
	free(cmd->fd_string[2]);
	i = 0;
	while (i < cmd->ac)
	{
		free(cmd->av[0]);
		i++;
	}
}

static void	del_jobs(void *data)
{
	t_job *job;

	job = (t_job *)data;
	if (job == NULL)
		return ;
	ft_lstdel(&job->cmd_lst, del_cmd);
}

void	free_list_job(t_list **jobs)
{
	ft_lstdel(jobs, del_jobs);
}
