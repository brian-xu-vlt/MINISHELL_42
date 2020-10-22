#include "minishell_bonus.h"

static void	child_process(const char *binary_full_path, const t_cmd *command)
{
	int		ret;
	char 	**envp;
	t_list	*env_lst;

	env_lst = get_env_list(GET);
	export_env(env_lst, "toto=42");
	envp = get_envp(env_lst);
	//	envp = get_envp(tmp_env_lst);

//	signal_manager(SIG_MODE_NORMAL);
	ret = execve(binary_full_path, command->av, envp); ////////////////// see p82 for failure!
	free_envp(envp);
	if (ret == FAILURE)
		print_set_errno(ENOENT, command->name, NULL);
	exit (ret);
}

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
		ms_setenv_int(get_env_list(GET), "!", (int)pid, F_OVERWRITE);
		pid = waitpid(pid, &wstatus, WUNTRACED);
	}
	else if (pid == 0)
		child_process(binary_full_path, command);
	else if (pid == FAILURE)
		return (FAILURE);
	return (manage_exit_status(wstatus, pid));
}
