#include "minishell_bonus.h"


static void	child_process(const char *binary_full_path, const t_cmd *command)
{
	int	ret;
	
	ret = execve(binary_full_path, command->av, get_env_data(GET)->envp); ////////////////// see p82 for failure!
	if (ret == FAILURE)
		print_set_errno(ENOENT, command->name, NULL);
	exit(ret);
}

static int	manage_exit_status(int wstatus, pid_t pid)
{
	int		ret;

	ret = 0;
	if (WIFEXITED(wstatus) == TRUE)
	{
		ret = WEXITSTATUS(wstatus);
		ft_printf("Exit status == %i", ret);
	}
	else if (WIFSIGNALED(wstatus) == TRUE)
	{
		ret = WTERMSIG(wstatus);
		ft_printf("PID %i Got a signal %i ", pid, ret);
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
	{
		ret = WSTOPSIG(wstatus);
		ft_printf("Got a STOPED by pid %d", ret);
	}
	ft_printf("\n");
	return (ret);
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

int				execute_bin(const char *binary_full_path, const t_cmd *command)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = fork_process();
	if (pid != 0 && pid != FAILURE)
	{
	//	kill(pid, SIGSTOP);
		ms_setenv_int("!", (int)pid, TRUE, TRUE);// ATTENTION // // ATTENTION //// ATTENTION // CHANGE TRUE, TRUE to TRUE, FALSE flags !!
		pid = waitpid(pid, &wstatus, WUNTRACED);
	}
	else if (pid == 0)
		child_process(binary_full_path, command);
	else if (pid == FAILURE)
		return (FAILURE);
	return (manage_exit_status(wstatus, pid));
}
