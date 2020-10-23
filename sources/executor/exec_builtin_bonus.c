#include "minishell_bonus.h"

int	exec_builtin(const t_cmd *command, int p_in[2], int p_out[2])
{
	int					i;
	int					ret_value;
	static const int	builtins_nb = 4;
	static const char	*builtin_names[builtins_nb] = 
		{ "exit", "env", "export", "unset" };
	int					(*builtin_functions[builtins_nb])(int, char **) = 
		{ exit_builtin, env_builtin, export_builtin, unset_builtin };

	i = 0;
	if (p_in[R_END] != -1 && p_in[W_END] != -1)
	{
		dup2(p_in[R_END], STDIN_FILENO);
		close(p_in[W_END]);
	}
	if (p_out[R_END] != -1 && p_out[W_END] != -1)
	{
		dup2(p_out[W_END], STDOUT_FILENO);
		close(p_out[R_END]);
	}
	while (i < builtins_nb)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			ret_value = (builtin_functions[i])(command->ac, command->av);
		i++;
	}
	return (ret_value);
}

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

