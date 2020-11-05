#include "minishell_bonus.h"

int	exec_builtin(const t_cmd *command)
{
	int					i;
	int					ret_value;
	static const int	builtins_nb = 4;
	static const char	*builtin_names[builtins_nb] = {
		"exit", "env", "export", "unset" };
	static int			(*builtin[builtins_nb])(int, char **, char **) = {
		exit_builtin, env_builtin, export_builtin, unset_builtin };

	i = 0;
	while (i < builtins_nb)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			ret_value = (builtin[i])(command->ac, command->av, command->envp);
		i++;
	}
	return (ret_value);
}
