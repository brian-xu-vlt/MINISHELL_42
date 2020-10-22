#include "minishell_bonus.h"
/*

*/
static int		prepare_and_exec_command(const t_cmd *command)
{
	int		ret_value;

	ret_value = -1;
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
