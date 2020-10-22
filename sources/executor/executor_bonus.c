#include "minishell_bonus.h"
/*

*/
static int		prepare_and_exec_command(const t_cmd *command)
{
//	char	*bin_dir;
//	char	*bin_full_path;
	int		ret_value;

	ret_value = -1;
	/*
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
	*/
	ret_value = execute_bin(command->name, command);
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
	ms_setenv_int(get_env_list(GET), "?", ret_value, F_OVERWRITE | F_EXPORT); //  ATTENTION ///////// remove F_EXPORT flag
	ft_printf("\n$? == %d\n", get_env_value_int(get_env_list(GET), "?")); // DEBUG
}
