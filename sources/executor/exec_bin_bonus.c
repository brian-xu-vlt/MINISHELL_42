#include "minishell_bonus.h"

static void	child_process(const char *name, const t_cmd *command)
{
	int		i;
	int		ret;
	char 	*full_path;
	char 	**envp;
	char	**path_list;

	ret = 0;
	signal_manager(SIG_MODE_NORMAL);
	export_execution_context_env(command);
	path_list = get_all_path_directories();
	envp = get_envp(get_env_list(GET));
	i = 0;
	while (path_list[i] != NULL)
	{
		full_path = get_exec_path(path_list[i], name);
		ft_printf("trying .... %s\n", full_path);
		if (full_path != NULL)
			ret = execve(full_path, command->av, envp); ////////////////// see p82 for failure!
		free(full_path);
		i++;
	}
	if (path_list[i] == NULL)
		print_set_errno(0, "command not found", command->name, NULL);
	else
		print_set_errno(errno, NULL, command->name, NULL);
	free_char_arr(path_list);
	free_char_arr(envp);
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

int				execute_bin(const char *name, const t_cmd *command,
													int p_in[2], int p_out[2])
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = fork_process();
	if (pid == FAILURE)
		return (FAILURE);
	else if (pid == 0)
	{
		if (p_in[R_END] != -1 && p_in[W_END] != -1)
		{
			dup2(p_in[R_END], STDIN_FILENO);
			close(p_in[W_END]);
		}
		if (p_out[R_END] != -1 && p_out[W_END] != -1)
		{
			dup2(p_out[W_END], STDOUT_FILENO);
			close(p_out[R_END]);
		}

		child_process(name, command);
	}
	else if (pid != 0 && pid != FAILURE)
	{
		ms_setenv_int(get_env_list(GET), "!", (int)pid, F_OVERWRITE);
//		pid = waitpid(pid, &wstatus, WUNTRACED);
	}
	return (manage_exit_status(wstatus, pid));
}
