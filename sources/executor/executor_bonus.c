#include "minishell_bonus.h"

static void		exec_subshell(const t_cmd *command, int p_in[2], int p_out[2])
{
	pid_t	pid;
	int		ret;
ft_printf("KIKOO\n\n\n\n");

	pid = fork_process();
	if (pid == FAILURE) 						//implement error managment
		return ;
	else if (pid == 0)
	{
		signal_manager(SIG_MODE_DEFAULT);
		dup_pipes(command, p_in, p_out);
		if (is_builtin(command) == TRUE)
			ret = exec_builtin(command);
		else	
			ret = exec_binary(command);
		if (command->redirection & F_REDIRECT_IN)
			close(command->fd[STDIN_FILENO]);
		if (command->redirection & F_REDIRECT_OUT)
			close(command->fd[STDOUT_FILENO]);
		ft_printf("exit subshell = %d\n\n", ret);
		exit(ret);
	}
	else if (pid != 0 && pid != FAILURE)
	{
		signal_manager(SIG_MODE_EXEC);
		ms_setenv_int(get_env_list(GET), "!", (int)pid, F_OVERWRITE);
	}
}

static int		is_builtin_executable(const int nb_cmd, const t_cmd *command)
{
	return (ft_strequ(command->name, "exit") == TRUE || 
		(nb_cmd == 1 && is_builtin(command) == TRUE 
		&& command->redirection == F_NO_REDIRECT));
}

static int		execution_process(const t_cmd *command, const int nb_cmd,
												int p_in[2], int p_out[2])
{
	int		ret;

	ret = 0;

	// open files with lila's functions
//	if (nb_cmd == 1 && command->name == NULL && command->env != NULL)
		//DO ASSIGNATIONS export_execution_context_env(command);
//	else if (ft_strequ(command->name, "exit") == TRUE)
	
	if ((command->redirection & F_REDIRECT_FAILURE) == FALSE)
	{
		if (is_builtin_executable(nb_cmd, command) == TRUE)
			ret = exec_builtin(command);
		else
			exec_subshell(command, p_in, p_out);
	}
	else
		return (-1);
	return (ret);
}

static void		do_pipe(int pipe_fd[2])
{
	int		pipe_ret;

	pipe_ret = pipe(pipe_fd);
	if (pipe_ret == FAILURE)
		print_set_errno(errno, NULL, "do pipe: ", NULL);
}

static void		waiter(int ret)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = SUCCESS;
	while (pid != FAILURE)
		pid = wait(&wstatus);
	manage_exit_status(ret, wstatus, pid);
}

static void		executor_loop(const t_job *job, int p_in[2], int p_out[2])
{
	int		ret;
	size_t	i;
	t_list	*cmd_cursor;

	i = 0;
	cmd_cursor = job->cmd_lst;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
		if (i < job->nb_cmd - 1)
			do_pipe(p_out);
		ret = execution_process(cmd_cursor->content, job->nb_cmd, p_in, p_out);
		close_pipe_end(p_in[R_END]);
		close_pipe_end(p_in[W_END]);
		if (i < job->nb_cmd - 1)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		cmd_cursor = cmd_cursor->next;
		i++;
	}
	waiter(ret);
}

void			executor(const t_job *job)
{
	int		p_in[2];
	int		p_out[2];

	if (job != NULL && job->cmd_lst != NULL)
	{
		ft_memset(p_in, UNSET, sizeof(int[2]));
		ft_memset(p_out, UNSET, sizeof(int[2]));
		executor_loop(job, p_in, p_out);
	}
}
