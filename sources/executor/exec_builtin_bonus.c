#include "minishell_bonus.h"

# define	NB_BUILTIN	4 

int			exec_builtin(t_cmd *cmd)
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
		if (ft_strequ((char *)cmd->name, (char *)builtin_names[i]) == TRUE)
		{
			ret_value = (builtin[i])(cmd->ac, cmd->av, cmd->envp);
			return (ret_value);
		}
		i++;
	}
	return (0);
}