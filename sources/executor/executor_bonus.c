#include "minishell_bonus.h"

static void		waiter(const t_job *job, const t_cmd *command, int ret)
{
	pid_t	pid;
	int		wstatus;
	int		exit_status;

	wstatus = 0;
	pid = SUCCESS;
	if (is_solo_builtin(job->nb_cmd, command) == TRUE)
		ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
	else
	{
		while (pid != FAILURE)
		{
			pid = wait(&wstatus);
			if (pid == job->last_pid)
			{
				exit_status = manage_subshell_exit_status(wstatus);
				ms_setenv_int(get_env_list(GET), "?", exit_status, F_OVERWRITE);
			}
		}
	}
}

static void		preprocess_command(const t_cmd *command)
{
	if (command->ac == 0 && command->count_assign != 0)
		export_envp_content(command);
	process_open_file((t_cmd *)command); 					//change to const in prototype
}

static void		execution_loop(t_job *job, int p_in[2], int p_out[2])
{
	int		ret;
	t_list	*cmd_cursor;
	size_t	i;

	i = 0;
	cmd_cursor = job->cmd_lst;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
		preprocess_command(cmd_cursor->content);
		if (is_last_cmd(i, job->nb_cmd) == FALSE)
			do_pipe(p_out);
		ret = execution_process(job, cmd_cursor->content, p_in, p_out);
		if (is_last_cmd(i, job->nb_cmd) == FALSE)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		if (is_last_cmd(i, job->nb_cmd) == TRUE)
			waiter(job, cmd_cursor->content, ret);
		cmd_cursor = cmd_cursor->next;
		i++;
	}
}

void			executor(t_job *job)
{
	int		p_in[2];
	int		p_out[2];

	if (is_valid_job(job) == FALSE)
		return ;
	ft_memset(p_in, UNSET, sizeof(int[2]));
	ft_memset(p_out, UNSET, sizeof(int[2]));
	execution_loop(job, p_in, p_out);
}