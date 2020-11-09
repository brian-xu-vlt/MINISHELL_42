#include "minishell_bonus.h"

static void		child_process(const t_cmd *command, int p_in[2], int p_out[2])
{
	int		ret;

	export_envp_content(command);
	signal_manager(SIG_MODE_DEFAULT);
	dup_pipes(command, p_in, p_out);
	ret = 1;
	if ((command->redirection & F_REDIRECT_FAILURE) == FALSE)
	{
		if (is_builtin(command) == TRUE)
			ret = exec_builtin(command);
		else
			ret = exec_binary(command);
	}
	if (command->redirection & F_REDIRECT_IN)
		close(command->fd[STDIN_FILENO]);
	if (command->redirection & F_REDIRECT_OUT)
		close(command->fd[STDOUT_FILENO]);
	exit(ret);
}

static void		exec_subshell(t_job *job, const t_cmd *command,
													int p_in[2], int p_out[2])
{
	pid_t	pid;

	pid = fork_process();
	if (pid == 0)
		child_process(command, p_in, p_out);
	else if (pid > 0)
	{
		signal_manager(SIG_MODE_EXEC);
		job->last_pid = pid;
		//ms_setenv_int(get_env_list(GET), "!LAST_PID", (int)pid, F_OVERWRITE);
	}
}

static int		exec_process(t_job *job, const t_cmd *command,
													int p_in[2], int p_out[2])
{
	int		ret;

	ret = 0;
	if (is_solo_builtin(job->nb_cmd, command) == TRUE)
		ret = exec_builtin(command);
	else
		exec_subshell(job, command, p_in, p_out);
	close_pipe_end(p_in[R_END]);
	close_pipe_end(p_in[W_END]);
	return (ret);
}

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
			//if (pid == get_env_value_int(get_env_list(GET), "!LAST_PID"))
			if (pid == job->last_pid)
			{
				exit_status = manage_subshell_exit_status(wstatus);
				ms_setenv_int(get_env_list(GET), "?", exit_status, F_OVERWRITE);
			}
		}
	}
}

// extract function from executor
static void		preprocess_command(const t_cmd *command)
{
	if (command->ac == 0 && command->count_assign != 0)
		export_envp_content(command);
	process_open_file((t_cmd *)command); 					//change to const in prototype
}


void			executor(t_job *job)
{
	int		p_in[2];
	int		p_out[2];
	int		ret;
	size_t	i;
	t_list	*cmd_cursor;

	if (is_valid_job(job) == FALSE)
		return ;
	ft_memset(p_in, UNSET, sizeof(int[2]));
	ft_memset(p_out, UNSET, sizeof(int[2]));
	cmd_cursor = job->cmd_lst;
	i = 0;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
		preprocess_command(cmd_cursor->content);
		if (is_last_cmd(i, job->nb_cmd) == FALSE)
			do_pipe(p_out);
		ret = exec_process(job, cmd_cursor->content, p_in, p_out);
		if (is_last_cmd(i, job->nb_cmd) == FALSE)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		if (is_last_cmd(i, job->nb_cmd) == TRUE)
			waiter(job, cmd_cursor->content, ret);
		cmd_cursor = cmd_cursor->next;
		i++;
	}
}
