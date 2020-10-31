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
	i = 0;
	while (i < cmd->count_assign)
	{
		free(cmd->envp[i]);
		i++;
	}
	i = 0;
	if (cmd->tab_redir != NULL)
	{
		while (i < cmd->count_redir)
		{
			free(cmd->tab_redir[i]);
			i++;
		}
		free(cmd->tab_redir);
	}
	if (cmd->envp != NULL)
		free(cmd->envp);
	free(cmd->av);
	free(cmd->tab_assign);
	free(cmd->tab_exp);
	free(cmd);
}

static void del_jobs(void *data)
{
	t_job *job;

	job = (t_job *)data;
	if (job == NULL)
		return ;
	ft_lstdel(&job->cmd_lst, del_cmd);
	free(job);
}

void free_list_job(t_list **jobs)
{
	ft_lstdel(jobs, del_jobs);
}
