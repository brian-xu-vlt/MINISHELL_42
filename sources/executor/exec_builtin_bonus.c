#include "minishell_bonus.h"

int	is_builtin(const t_cmd *command)
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

int	exec_builtin(const t_cmd *command)
{
	int					i;
	int					ret_value;
	static const int	builtins_nb = 4;
	static const char	*builtin_names[builtins_nb] = 
		{ "exit", "env", "export", "unset" };
	int					(*builtin_functions[builtins_nb])(int, char **) = 
		{ exit_builtin, env_builtin, export_builtin, unset_builtin };

	i = 0;
	while (i < builtins_nb)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			ret_value = (builtin_functions[i])(command->ac, command->av);
		i++;
	}
	exit (42);
	return (ret_value);
}
