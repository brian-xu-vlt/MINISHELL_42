#include "minishell_bonus.h"

static int	manage_exit_status(int wstatus, pid_t pid)
{
	int		ret;

	ret = 0;
	if (WIFEXITED(wstatus) == TRUE)
	{
		ret = WEXITSTATUS(wstatus);
		ft_printf("\nEXIT_MANAGER : Exit status == %i", ret);
	}
	else if (WIFSIGNALED(wstatus) == TRUE)
	{
		ret = WTERMSIG(wstatus);
		ft_printf("\nEXIT_MANAGER : PID %i Got a signal %i ", pid, ret);
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
	{
		ret = WSTOPSIG(wstatus);
		ft_printf("\nEXIT_MANAGER : Got a STOPED by pid %d", ret);
	}
	ft_printf("\n");
	return (ret);
}

static int	is_builtin(const t_cmd *command)
{
	int					i;
	static const int	builtins_nb = 4;
	static const char	*builtin_names[builtins_nb] = 
		{ "exit", "env", "export", "unset" };

	i = 0;
	while (i < builtins_nb)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void		dup_pipes(int p_in[2], int p_out[2])
{
	if (p_in[R_END] != UNSET || p_in[W_END] != UNSET)
	{
		dup2(p_in[R_END], STDIN_FILENO);
		close(p_in[W_END]);
		p_in[W_END] = UNSET;
	}
	if (p_out[R_END] != UNSET || p_out[W_END] != UNSET)
	{
		dup2(p_out[W_END], STDOUT_FILENO);
		close(p_out[R_END]);
		p_out[R_END] = UNSET;
	}
}

static pid_t	fork_process(void)
{
	pid_t	pid_ret;

	errno = 0;
	pid_ret = fork();
	while (pid_ret == FAILURE && errno == EAGAIN)
		pid_ret = fork();
	if (pid_ret == FAILURE)
		exit_routine_le(ERR_FORK);
	return (pid_ret);
}

static void		exec_subshell(const t_cmd *command, int p_in[2], int p_out[2])
{
	pid_t	pid;
	
dprintf(STDERR_FILENO, "INSIDE SUBSHELL !!!!!!!!!!!!!!\n");
	
	pid = fork_process();
	if (pid == FAILURE) //implement error managment
		return ;
	else if (pid == 0)
	{
		dup_pipes(p_in, p_out);
		if (is_builtin(command) == TRUE)
			exec_builtin(command);
		else	
			exec_binary(command);
		exit(42); //to change
	}
	else if (pid != 0 && pid != FAILURE)
		ms_setenv_int(get_env_list(GET), "!", (int)pid, F_OVERWRITE);
}
static int		execution_process(const t_cmd *command, const int nb_cmd,
												int p_in[2], int p_out[2])
{
	if (ft_strequ(command->name, "exit") == TRUE)
		exec_builtin(command);
	else if (nb_cmd == 1 && is_builtin(command) == TRUE)
		exec_builtin(command);
	else
		exec_subshell(command, p_in, p_out);
	return (21);
}

static void		close_pipe(int pipe_to_close[2])
{
	if (pipe_to_close[R_END] != UNSET)
	{
		close(pipe_to_close[R_END]);
		pipe_to_close[R_END] = UNSET;
	}
	if (pipe_to_close[W_END] != UNSET)
	{
		close(pipe_to_close[W_END]);	
		pipe_to_close[W_END] = UNSET;
	}
}

void			executor(const t_job *job)
{
	size_t	i;
	int		ret_value;
	t_list	*cmd_cursor;
	int		p_in[2];
	int		p_out[2];
	pid_t	pid;
	int		wstatus;
	
	if (job == NULL || job->cmd_lst == NULL)
		return ;
	i = 0;
	ft_memset(p_in, UNSET, sizeof(int[2]));
	ft_memset(p_out, UNSET, sizeof(int[2]));
	cmd_cursor = job->cmd_lst;
	while (i < job->nb_cmd && cmd_cursor->content != NULL)
	{
		ret_value = 0;
		if (i < job->nb_cmd - 1)
			pipe(p_out);
		execution_process(cmd_cursor->content, job->nb_cmd, p_in, p_out);
		close_pipe(p_in);
		if (i < job->nb_cmd - 1)
			ft_memmove(p_in, p_out, sizeof(int[2]));
		else
			close_pipe(p_out);
		cmd_cursor = cmd_cursor->next;
		pid = wait(&wstatus);
		i++;
	}
	ms_setenv_int(get_env_list(GET), "?", ret_value, F_OVERWRITE);
	ft_printf("\n(exec) $? = %d\n", get_env_value_int(get_env_list(GET), "?"));
	manage_exit_status(wstatus, pid);
}


/*	
	if (ret_value != 0 || errno != 0)
		ret_value = 128 + ret_value;
*/
