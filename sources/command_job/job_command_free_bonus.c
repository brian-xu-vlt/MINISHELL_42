#include "minishell_bonus.h"

static void	del_cmd(void *data)
{
	t_cmd *cmd;

	cmd = (t_cmd *)data;
	if (cmd == NULL)
		return ;
	free(cmd->fd_string[0]);
	free(cmd->fd_string[1]);
	free(cmd->fd_string[2]);
	if (cmd->av != NULL)
	{
		ft_printf("TU RENTRES ICI HEIN :)\n");//DEBUG
		ft_free_tab(cmd->ac, cmd->av);
		free(cmd->av);
	}
	if (cmd->envp != NULL)
	{
		ft_free_tab(cmd->count_assign, cmd->envp);
		free(cmd->envp);
	}
	if (cmd->tab_redir != NULL)
	{
		ft_free_tab(cmd->count_redir, cmd->tab_redir);
		free(cmd->tab_redir);
	}
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
