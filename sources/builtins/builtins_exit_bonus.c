#include "minishell_bonus.h"

// return int mais pas sur, peut etre juste utiliser le errno.

int	exit_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "exit";

	(void)envp;
	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		exit_routine_le("exit");
	return (SUCCESS);
}
