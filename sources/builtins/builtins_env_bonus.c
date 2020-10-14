#include "minishell_bonus.h"

// return int mais pas sur, peut etre juste utiliser le errno.

int	exit_builtin(int ac, char **av)
{
	const char	*builtin = "exit";

	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		exit_routine_le("exit");
	return (SUCCESS);
}

int	env_builtin(int ac, char **av)
{
	const char	*builtin = "env";

	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		print_env();
	else
	{
		print_set_errno(EINVAL, (char *)builtin, av[1]);
		return (FAILURE);
	}	
	return (SUCCESS);
}

int	assignation_builtin(int ac, char **av)
{
	int			i;

	// ADD CHECK BOOLEAN FOR ASSIGNATION
	i = 0;
	while (i < ac)
	{
		if (ft_isalpha(av[i][0]) == FALSE)
		{
			print_set_errno(EINVAL, NULL, av[i]);
			return (127);
		}
		i++;
	}
	i = 1; // change to 0 !!!!!!!!
	while (i < ac)
	{
		export_env(av[i]);
		i++;
	}
	return (SUCCESS);
}

int	export_builtin(int ac, char **av)
{
	const char	*builtin = "export";
	int			i;

	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		get_export_output();
	else
	{
		i = 1;
		while (i < ac)
		{
			if (ft_isalpha(av[i][0]) == TRUE)
				export_env(av[i]);
			else
				print_set_errno(EINVAL, (char *)builtin, av[i]);
			i++;
		}
	}
	if (errno != 0)
		return (BUILTIN_FAILURE);
	return (SUCCESS);
}

int	unset_builtin(int ac, char **av)
{
	const char	*builtin = "unset";
	int			i;

	if (ac == 1 || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else
	{
		i = 0;
		while (i < ac)
		{
			if (av[i][0] == '-')
				print_set_errno(EINVAL, (char *)builtin, av[i]);
			else
				unset_env(av[i]);
			i++;
		}
	}
	return (SUCCESS);
}
