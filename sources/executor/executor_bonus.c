#include "minishell_bonus.h"

static char		*create_full_path(const char *bin_dir, const char *bin_name)
{
	size_t	len_dir;
	size_t	len_name;
	char  	*full_path;

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

static int		is_absolute_path(const char *bin_name)
{
	return ((ft_strchr((char *)bin_name, '/') == NOT_FOUND) ? FALSE : TRUE);
}

static int		prepare_and_exec_command(const t_cmd *command)
{
	char	*bin_dir;
	char	*bin_full_path;
	int		ret_value;

	ret_value = -1;
	if (is_absolute_path(command->name) == TRUE)
		ret_value = execute_bin(command->name, command);
	else
	{
		bin_dir = locate_binary_file(command->name);
		if (bin_dir != NOT_FOUND)
		{
			bin_full_path = create_full_path(bin_dir, command->name);
			ret_value = execute_bin(bin_full_path, command);
			free(bin_dir);
			free(bin_full_path);
		}
		else
			ft_printf("%s: %s\n", command->name, ERR_NO_COMMAND);
	}
	if (ret_value != 0 || errno != 0)
		ret_value = 128 + ret_value;
	return (ret_value);
}

void			executor(const t_cmd *command)
{
	int		ret_value;

	ret_value = 0;
	if (command != NULL)
	{
		if (is_builtin(command) == TRUE)
			ret_value = exec_builtin(command);
		else
			ret_value = prepare_and_exec_command(command);
	}
	ms_setenv_int("?", ret_value, TRUE, FALSE);
	ft_printf("\n$? == %d\n", get_env_value_int("?")); // DEBUG
}
