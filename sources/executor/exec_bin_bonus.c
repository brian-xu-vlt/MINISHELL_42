#include "minishell_bonus.h"
/*
static void	debug_extra_av(const t_cmd *command)
{
	int		i;

	i = 0;
	ft_printf("\033[0;32mDEBUG EXTRA AV\n\033[0m");//DEBUG
	ft_printf("envp : %p\n", command->envp);//DEBUG
	while (command->av[i] != NULL)
	{
		if (command->av[i] != NULL && i > command->ac - 1)
		{
			free(command->av[i]);
			command->av[i] = NULL;
		}
		ft_printf("av[%d] %s\n", i, command->av[i]);
		i++;
	}
}
*/
static int	execution(const t_cmd *command, char *bin_full_path, char **envp)
{
	int		ret;

	errno = 0;
//	debug_extra_av(command);
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
	if (command->ac <= 0)
		return (0);
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
