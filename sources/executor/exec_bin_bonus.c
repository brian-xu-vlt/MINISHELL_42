#include "minishell_bonus.h"

static int	execution(const t_cmd *command, char *bin_full_path, char **envp)
{
	int		ret;

	errno = 0;
	ret = execve(bin_full_path, command->av, envp); /////// see p82 for failure!
	if (ret == FAILURE)
		print_set_errno(errno, NULL, bin_full_path, NULL);
	return (ret);
}

int			exec_binary(const t_cmd *command)
{
	int			ret;
	char		**envp;
	char		*bin_full_path;

	errno = 0;
	ret = 127;
	//	export_execution_context_env(command);
	bin_full_path = locate_binary_file(command->name);
	if (bin_full_path != NOT_FOUND)
	{
		envp = get_envp(get_env_list(GET));
		ret = execution(command, bin_full_path, envp);
		ret = (errno == EACCES) ? 126 : ret;
		free(bin_full_path);
		free_char_arr(envp);
	}
	else if (bin_full_path != NOT_FOUND && errno == EISDIR)
		ret = 126;
	return (ret);
}
