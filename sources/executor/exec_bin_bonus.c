#include "minishell_bonus.h"


static void	child_process(const char *binary_full_path, const t_cmd *command)
{
	int	ret;
	
	ret = execve(binary_full_path, command->av, get_env_data(GET)->envp);
	if (ret == FAILURE)
		print_set_errno(ENOENT, command->name, NULL);
	exit(ret);
}

static void	manage_exit_status(int wstatus, pid_t pid)
{
	if (WIFEXITED(wstatus) == TRUE)
		ft_printf("Exit status == %i\n", WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus) == TRUE)
	{
		ft_printf("PID %i Got a signal %i ", pid, WTERMSIG(wstatus));
		if (WCOREDUMP(wstatus) != FALSE)
			ft_printf("(core dumped)");
	}
	else if (WIFSTOPPED(wstatus) == TRUE)
		ft_printf("Got a STOPED by pid %d\n", WSTOPSIG(wstatus));
}

static pid_t	fork_process(void)
{
	pid_t	pid_ret;

	return (pid_ret = fork());
}

int				execute_bin(const char *binary_full_path, const t_cmd *command)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = fork_process();
	if (pid == 0)
		child_process(binary_full_path, command);
	else if (pid == FAILURE)
		return (FAILURE);
	else
	{
		ms_setenv_int("!", (int)pid, TRUE, TRUE);// ATTENTION // // ATTENTION //// ATTENTION // CHANGE TRUE, TRUE to TRUE, FALSE flags !!
		pid = waitpid(pid, &wstatus, WUNTRACED);
	}
	manage_exit_status(wstatus, pid);
	return (wstatus);
}
