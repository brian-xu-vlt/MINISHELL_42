#include "minishell_bonus.h"

static char **get_path_options(void)
{
	char	*path_env;

	path_env = vct_getstr(get_env_value_vct("PATH"));
	return (ft_split(path_env, ':'));
}

static char	*find_exec_path(char *exec_name)
{
	char	**path_options;

(void)exec_name;
	path_options = get_path_options();
	return (NULL);
}

void	executor(t_cmd *command)
{
	write(STDERR_FILENO, "\n", 1);
	if (command->ac != 0)
		execve(command->name, command->av, get_env_data(GET)->envp);
	find_exec_path(command->name);
}
