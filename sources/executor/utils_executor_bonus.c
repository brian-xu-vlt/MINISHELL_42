#include "minishell_bonus.h"

static const char	*ms_strsignal(int sig)
{
	int					i;
	static const int 	sig_nb = 15;
	static const int 	sig_list[sig_nb] = {
		SIGALRM, SIGVTALRM, SIGPROF,
		SIGABRT, SIGBUS, SIGSEGV, SIGHUP, SIGQUIT,
		SIGILL, SIGKILL, SIGSTOP, SIGCONT,
		SIGTSTP, SIGTERM, SIGPOLL };
	static const char 	*sig_str[sig_nb] = {
		"Alarm clock","Virtual Alarm clock", "Profiling timer expired",
		"Abort", "Bus Error", "Segmentation Fault", "Hangup", "Quit",
		"Illegal instruction", "Killed", "Stop process", "Continue Process",
		"Stop typed at terminal", "Termination signal", "I/O possible" };
	
	i = 0;
	while (i < sig_nb)
	{
		if (sig_list[i] == sig)
			return (sig_str[i]);
		i++;
	}
	return (NOT_FOUND);
}

static void	display_signal_str(int sig)
{
	const char	*sig_str;

	if ((sig_str = ms_strsignal(sig)) != NOT_FOUND)
		ft_printf("%s ", sig_str);
}

int	manage_exit_status(int ret, int wstatus, pid_t pid)
{
(void)pid;
	//ret = 0;
	if (WIFSIGNALED(wstatus) == TRUE)
	{
		ret = WTERMSIG(wstatus);
		display_signal_str(ret);
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
	{
		ret = WSTOPSIG(wstatus);
	//	ft_printf("\nEXIT_MANAGER : Got a STOPED by pid %d", ret);
	}
	else if (WIFEXITED(wstatus) == TRUE)
	{
		ret = WEXITSTATUS(wstatus);
	//	ft_printf("\nEXIT_MANAGER : Exit status == %i", ret);
	}
	ft_printf("\r\n");
	ms_setenv_int(get_env_list(GET), "?", ret, F_OVERWRITE);
	ft_printf("\n(exit_manager) $? = %d\n", get_env_value_int(get_env_list(GET), "?"));
	return (ret);
}
/*	
	system("ls -la /proc/$$/fd ; echo \"\n\"");
	if (ret != 0 || errno != 0)
		ret = 128 + ret;
*/

int	is_builtin(const t_cmd *command)
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

static int	open_file(t_cmd *command, int fd_fileno)
{
	int					open_flags;
	int					fd_return;

	open_flags = 0;
	if (fd_fileno == STDIN_FILENO)
		open_flags = O_RDONLY;
	else
	{
		if (command->redirection & F_REDIRECT_OUT_APPEND)
			open_flags = O_WRONLY | O_CREAT | O_APPEND;
		else if (command->redirection & F_REDIRECT_OUT)
			open_flags = O_WRONLY | O_CREAT | O_TRUNC;
	}
	fd_return = open(command->fd_string[fd_fileno], open_flags);
	if (fd_return < 0)
		print_set_errno(errno, NULL, command->fd_string[fd_fileno], NULL);
	command->fd[fd_fileno] = fd_return;
	return (fd_return);	
}

void		dup_pipes(const t_cmd *command, int p_in[2], int p_out[2])
{
	struct stat	statbuf;

	if (command->redirection & F_REDIRECT_IN)
		dup2(open_file((t_cmd *)command, STDIN_FILENO), STDIN_FILENO);
	else if (p_in[R_END] != UNSET && fstat(p_in[R_END], &statbuf) != FAILURE)
	{
		dup2(p_in[R_END], STDIN_FILENO);
		close_pipe_end(p_in[W_END]);
	}
	if (command->redirection & F_REDIRECT_OUT)
		dup2(open_file((t_cmd *)command, STDOUT_FILENO), STDOUT_FILENO);
	else if (p_out[W_END] != UNSET && fstat(p_out[W_END], &statbuf) != FAILURE)
	{
		dup2(p_out[W_END], command->fd[STDOUT_FILENO]);
		close_pipe_end(p_out[R_END]);
	}
}

pid_t	fork_process(void)
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

void		close_pipe_end(int pipe_to_close)
{
	int		close_ret;
	
	close_ret = 0;
	if (pipe_to_close != UNSET)
	{
		close_ret = close(pipe_to_close);
		if (DEBUG_MODE == TRUE && close_ret == FAILURE) // TO CHANGE BACK 
			print_set_errno(errno, NULL, "close pipe: ", NULL);
		pipe_to_close = UNSET;
	}
}
