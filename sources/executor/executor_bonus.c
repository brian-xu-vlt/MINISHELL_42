#include "minishell_bonus.h"

static void		child_process(const t_cmd *command, int p_in[2], int p_out[2])
{
	int		ret;

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

static void		exec_subshell(const t_cmd *command, int p_in[2], int p_out[2])
{
	pid_t	pid;

	pid = fork_process();
	if (pid == 0)
		child_process(command, p_in, p_out);
	else if (pid > 0)
	{
		signal_manager(SIG_MODE_EXEC);
		ms_setenv_int(get_env_list(GET), "!LAST_PID", (int)pid, F_OVERWRITE);
	}
}

static int		exec_process(const t_cmd *command, const int nb_cmd,
													int p_in[2], int p_out[2])
{
	int		ret;

	ret = 0;
	// open files with lila's functions
	//	if (nb_cmd == 1 && command->name == NULL && command->env != NULL)
	//DO ASSIGNATIONS export_execution_context_env(command);
	if (is_solo_builtin(nb_cmd, command) == TRUE)
		ret = exec_builtin(command);
	else
		exec_subshell(command, p_in, p_out);
	close_pipe_end(p_in[R_END]);
	close_pipe_end(p_in[W_END]);
	return (ret);
}

static void		waiter(const t_cmd *command, const int nb_cmd, int ret)
{
	pid_t	pid;
	int		wstatus;
	int		exit_status;

	wstatus = 0;
	pid = SUCCESS;
	if (is_solo_builtin(nb_cmd, command) == TRUE)
		ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
	else
	{
		while (pid != FAILURE)
		{
			pid = wait(&wstatus);
			if (pid == get_env_value_int(get_env_list(GET), "!LAST_PID"))
			{
				exit_status = manage_subshell_exit_status(wstatus);
				ms_setenv_int(get_env_list(GET), "?", exit_status, F_OVERWRITE);
			}
		}
	}
}

void			executor(const t_job *job)
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
		process_open_file(cmd_cursor->content);
		ft_printf("\033[0;32mDEBUG REDIR FINAL\n\033[0m");//DEBUG
		//debug_redir();
		if (is_last_cmd(i, job->nb_cmd) == FALSE)
			do_pipe(p_out);
		ret = exec_process(cmd_cursor->content, job->nb_cmd, p_in, p_out);
		if (is_last_cmd(i, job->nb_cmd) == FALSE)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		if (is_last_cmd(i, job->nb_cmd) == TRUE)
			waiter(cmd_cursor->content, job->nb_cmd, ret);
		cmd_cursor = cmd_cursor->next;
		i++;
	}
}
