#include "minishell.h"

static int	call_execve(const t_cmd *command, char *bin_full_path, char **envp)
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
	if (command->ac < 1)
		return (0);
	bin_full_path = locate_binary_file(command->name);
	if (errno == EISDIR)
		ret = 126;
	else if (bin_full_path != NOT_FOUND)
	{
		envp = get_envp(get_env_list(GET));
		ret = call_execve(command, bin_full_path, envp);
		ret = (errno != 0) ? 126 : ret;
		free(bin_full_path);
		free_char_arr(envp);
	}
	return (ret);
}
