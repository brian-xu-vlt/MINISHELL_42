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

int	env_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "env";
(void)envp;

	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		print_env(get_env_list(GET));
	else
	{
		print_set_errno(EINVAL, NULL, builtin, av[1]);
		return (FAILURE);
	}	
	return (SUCCESS);
}

int	export_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "export";
	int			i;
(void)envp;

	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		print_export_output(get_env_list(GET));
	else
	{
		i = 1;
		while (i < ac)
		{
			if (ft_isalpha(av[i][0]) == TRUE)
				export_env(get_env_list(GET), av[i]);
			else
				print_set_errno(EINVAL, NULL, builtin, av[i]);
			i++;
		}
	}
	if (errno != 0)
		return (BUILTIN_FAILURE);
	return (SUCCESS);
}

int	unset_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "unset";
	int			i;

(void)envp;
	if (ac == 1 || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else
	{
		i = 0;
		while (i < ac)
		{
			if (av[i][0] == '-')
				print_set_errno(EINVAL, NULL, builtin, av[i]);
			else
				unset_env(get_env_list(GET), av[i]);
			i++;
		}
	}
	return (SUCCESS);
}
