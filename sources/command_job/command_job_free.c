#include "minishell_bonus.h"

static void	del_cmd(void *data)
{
	t_cmd *cmd;
	int		i;

	cmd = (t_cmd *)data;
	if (cmd == NULL)
		return ;
	free(cmd->fd_string[0]);
	free(cmd->fd_string[1]);
	free(cmd->fd_string[2]);
	i = 0;
	while (i < cmd->ac)
	{
		free(cmd->av[i]);
		i++;
	}
	free(cmd->av);
	free(cmd);
}

static void	del_jobs(void *data)
{
	t_job *job;

	job = (t_job *)data;
	if (job == NULL)
		return ;
	ft_lstdel(&job->cmd_lst, del_cmd);
	free(job);
}

void	free_list_job(t_list **jobs)
{
	ft_lstdel(jobs, del_jobs);
}
