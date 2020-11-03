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

pid_t	fork_process(void)
{
	pid_t	pid_ret;

	errno = 0;
	pid_ret = fork();
	while (pid_ret == FAILURE && errno == EAGAIN)
		pid_ret = fork();
	if (pid_ret == FAILURE)
		exit_routine_le(ERR_FORK);
	return (pid_ret);
}

int		is_solo_builtin(const int nb_cmd, const t_cmd *command)
{
	return (ft_strequ(command->name, "exit") == TRUE || 
		(nb_cmd == 1 && is_builtin(command) == TRUE 
		&& command->redirection == F_NO_REDIRECT));
}

