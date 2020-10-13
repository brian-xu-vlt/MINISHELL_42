#include "minishell_bonus.h"

static char		*create_full_path(const char *bin_dir, const char *bin_name)
{
	size_t				len_dir;
	size_t				len_name;
	char				*full_path;

	len_dir = ft_strlen(bin_dir);
	len_name = ft_strlen(bin_name);
	full_path = (char *)ft_calloc(len_dir + len_name + 3, sizeof(char));
	if (full_path == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memcpy(full_path, bin_dir, len_dir);
	ft_memcpy(full_path + len_dir, "/", 1);
	ft_memcpy(full_path + len_dir + 1, bin_name, len_name);
	return (full_path);
}

static int		exec_minishell_builtin(const t_cmd *command)
{
	int					i;
	static const int	builtins_nb = 3;
	static const char	*builtin_names[builtins_nb] = 
		{ "env", "export", "unset" };
	int					(*builtin_functions[builtins_nb])(int, char **) = 
		{ env_builtin, export_builtin, unset_builtin };

	i = 0;
	if (ft_strequ((char *)command->name, "exit") == TRUE)
		exit_routine_le("exit");
	while (i < builtins_nb)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			return ((builtin_functions[i])(command->ac, command->av));
		i++;
	}
	return (FAILURE);
}

static int		is_builtin(const t_cmd *command)
{
	int					i;
	static const int	builtins_nb = 4;
	static const char	*builtin_names[builtins_nb] = 
		{ "exit", "env", "export", "unset" };

	i = 0;
	while (i < builtins_nb)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int		is_absolute_path(const char *bin_name)
{
	return ((ft_strchr((char *)bin_name, '/') == NOT_FOUND) ? FALSE : TRUE);
}

void			executor(const t_cmd *command)
{
	int					ret_value;
	char				*bin_dir;
	char				*binary_full_path;

	ret_value = 0;
	if (command == NULL)
		return ;
	if (is_builtin(command) == TRUE)
		ret_value = exec_minishell_builtin(command);
	else if (is_absolute_path(command->name) == TRUE)
		ret_value = execute_bin(command->name, command);
	else
	{
		bin_dir = locate_binary_file(command->name);
		if (bin_dir == NOT_FOUND)
		{
			ret_value = -1;
			ft_printf("%s: %s\n", command->name, ERR_NO_COMMAND);
		}
		else
		{
			binary_full_path = create_full_path(bin_dir, command->name);
			ret_value = execute_bin(binary_full_path, command);
			free(bin_dir);
			free(binary_full_path);
		}
	}
		if (ret_value < 0)
			ret_value = 128 + ret_value;
	ms_setenv_int("?", ret_value, TRUE, TRUE); // ATTENTION !! CHANGE TRUE, TRUE to TRUE, FALSE
	ft_printf("record... %d as ? env\n", ret_value);
}
