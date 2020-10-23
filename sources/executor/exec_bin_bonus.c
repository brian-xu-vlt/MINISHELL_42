#include "minishell_bonus.h"

static void	child_process_binary(const char *name, const t_cmd *command)
{
	int		i;
	int		ret;
	char 	*full_path;
	char 	**envp;
	char	**path_list;

	ret = 0;
//	signal_manager(SIG_MODE_NORMAL);
	export_execution_context_env(command);
	path_list = get_all_path_directories();
	envp = get_envp(get_env_list(GET));
	i = 0;
	while (path_list[i] != NULL)
	{
		full_path = get_exec_path(path_list[i], name);
	//	ft_printf("trying .... %s\n", full_path);
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

void			execute_bin(const char *name, const t_cmd *command,
									int p_in[2], int p_out[2])
{
	pid_t	pid;

	if (ft_strequ(command->name, "exit") == TRUE)
		exit_routine_le(ERR_NO_MESSAGE);
	pid = fork_process();
	if (pid == FAILURE)
		return;
	else if (pid == 0)
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
		if (is_builtin(command) == TRUE)
			exec_builtin(command);
		else	
			child_process_binary(name, command);
	}
	else if (pid != 0 && pid != FAILURE)
		ms_setenv_int(get_env_list(GET), "!", (int)pid, F_OVERWRITE);
}
