#include "minishell_bonus.h"

int	exec_binary(const t_cmd *command)
{
	int		i;
	int		ret;
	char 	*full_path;
	char 	**envp;
	char	**path_list;

	ret = 0;
	export_execution_context_env(command);
	path_list = get_all_path_directories();
	envp = get_envp(get_env_list(GET));
	i = 0;
	while (path_list[i] != NULL)
	{
		errno = 0;
		if (is_absolute_path(command->name) == TRUE)
			full_path = ft_strdup(command->name);
		else
			full_path = get_exec_path(path_list[i], command->name);
//		ft_printf("trying .... %s\n", full_path);
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
	if (errno == EACCES)
		ret = 126;
	free_char_arr(path_list);
	free_char_arr(envp);
	return (ret);
}
