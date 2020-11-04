#include "minishell_bonus.h"

static int	execution(const t_cmd *command, char **path_list, char **envp)
{
	int		ret;
	int		i;
	char 	*full_path;

	ret = 0;
	i = 0;
	while (path_list[i] != NULL)
	{
		errno = 0;
		if (is_absolute_path(command->name) == TRUE)
			full_path = ft_strdup(command->name);
		else
			full_path = get_exec_path(path_list[i], command->name);
		if (full_path != NULL && errno != EACCES)
			ret = execve(full_path, command->av, envp); ////////////////// see p82 for failure!
		free(full_path);
		i++;
	}
	if (path_list[i] == NULL)
	{
		print_set_errno(0, "command not found", command->name, NULL);
		ret = 127;
	}
	else
		print_set_errno(errno, NULL, command->name, NULL);
	return (ret);
}

int			exec_binary(const t_cmd *command)
{
	int			ret;
	char		**envp;
	char		**path_list;

	ret = 0;
	export_execution_context_env(command);
	path_list = get_all_path_directories();
	envp = get_envp(get_env_list(GET));
	if (path_list != NULL)
		ret = execution(command, path_list, envp);
	if (errno == EACCES)
		ret = 126;
	free_char_arr(path_list);
	free_char_arr(envp);
	return (ret);
}
