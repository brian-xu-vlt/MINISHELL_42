#include "minishell_bonus.h"

static void	free_cmd(size_t size, void *data)
{
	ft_free_tab(size, data);
	free(data);
}

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
		free_cmd(cmd->ac, cmd->av);
	if (cmd->envp != NULL)
		free_cmd(cmd->count_assign, cmd->envp);
	if (cmd->tab_redir != NULL)
		free_cmd(cmd->count_redir, cmd->tab_redir);
	free(cmd->tab_assign);
	free(cmd->tab_exp);
	free(cmd->type);
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

void		free_list_job(t_list **jobs)
{
	ft_lstdel(jobs, del_jobs);
}
