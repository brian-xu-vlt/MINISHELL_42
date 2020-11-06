#include "minishell_bonus.h"

# define	NB_BUILTIN	4 

int	exec_builtin(const t_cmd *command)
{
	int					i;
	int					ret_value;
	static const char	*builtin_names[NB_BUILTIN] = {
		"exit", "env", "export", "unset" };
	static int			(*builtin[NB_BUILTIN])(int, char **, char **) = {
		exit_builtin, env_builtin, export_builtin, unset_builtin };

	i = 0;
	ret_value = 0;
	while (i < NB_BUILTIN)
	{
		if (ft_strequ((char *)command->name, (char *)builtin_names[i]) == TRUE)
			ret_value = (builtin[i])(command->ac, command->av, command->envp);
		i++;
	}
	return (ret_value);
}