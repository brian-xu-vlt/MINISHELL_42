#include "minishell_bonus.h"

static char		*create_full_path(const char *dir, const char *bin_name)
{
	size_t	len_dir;
	size_t	len_name;
	char  	*full_path;

	len_dir = ft_strlen(dir);
	len_name = ft_strlen(bin_name);
	full_path = (char *)ft_calloc(len_dir + len_name + 3, sizeof(char));
	if (full_path == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memcpy(full_path, dir, len_dir);
	ft_memcpy(full_path + len_dir, "/", 1);
	ft_memcpy(full_path + len_dir + 1, bin_name, len_name);
	return (full_path);
}

static char		**get_all_path_directories(void)
{
	char	*path_env;

	path_env = vct_getstr(get_env_value_vct(get_env_list(GET), "PATH"));
	if (path_env == NOT_FOUND)
		return (NULL);
	else
		return (ft_split(path_env, ':'));
}

static int		is_absolute_path(const char *bin_name)
{
	return ((ft_strchr((char *)bin_name, '/') == NOT_FOUND) ? FALSE : TRUE);
}

static char	*get_full_path(char *dir, const char *name)
{
	if (is_absolute_path(name) == TRUE)
		return (ft_strdup(name));
	else if (dir != NULL)
		return (create_full_path(dir, name));
	else
		return (NULL);
}

static void	export_execution_context_env(const t_cmd *command)
{
	t_list	*env_lst;

	env_lst = get_env_list(GET);			//insert here : function to assign content of t_cmd->envp
	(void)command;
	// if (command->envp != NULL)
	// 		do export of each envp here
//	export_env(env_lst, "PATH=/tmp/bin:/bin"); 	// TEST
}

static void	child_process(const char *name, const t_cmd *command)
{
	int		ret;
	char 	*full_path;
	char 	**envp;
	char	**path_list;

	ret = 0;
	signal_manager(SIG_MODE_NORMAL);
	export_execution_context_env(command);
	path_list = get_all_path_directories();
	envp = get_envp(get_env_list(GET));
	while (ret == FAILURE && errno == ENOENT)
	{
		full_path = get_full_path(*path_list, name);
		if (full_path != NULL)
			ret = execve(full_path, command->av, envp); ////////////////// see p82 for failure!
		else
			break ;
		free(full_path);
		path_list++;
	}
	if (path_list != NULL)
		free_char_arr(path_list);
	free_char_arr(envp);
	print_set_errno(errno, command->name, NULL);
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

int				execute_bin(const char *name, const t_cmd *command)
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
		child_process(name, command);
	else if (pid == FAILURE)
		return (FAILURE);
	return (manage_exit_status(wstatus, pid));
}
