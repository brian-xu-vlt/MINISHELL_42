#include "minishell_bonus.h"

int	env_builtin(int ac, char **av)
{
	const char	*builtin = "env";

	if (ft_strncmp(av[0], builtin, ft_strlen(builtin) + 1) != 0)
		return (0);
	if (ac == 1)
		print_env(ALL);
	else
	{
		errno = EINVAL;
		print_enno(builtin, av[1]);
		return (FAILURE);
	}	
	return (SUCCESS);
}

int	export_builtin(int ac, char **av)
{
	const char	*builtin = "export";
	int			i;

	if (ft_strncmp(av[0], builtin, ft_strlen(builtin) + 1) != 0)
		return (0);
	if (ac == 1)
		get_export_output();
	else
	{
		i = 0;
		while (i < ac && av[i][0] != '-')
			export_env(av[i++]);
		if (av[i][0] == '-')
		{
			errno = EINVAL;
			print_enno(builtin, av[i]);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	unset_builtin(int ac, char **av)
{
	const char	*builtin = "unset";
	int			i;

	if (ac == 1 || ft_strncmp(av[0], builtin, ft_strlen(builtin) + 1) != 0)
		return (0);
	else
	{
		i = 0;
		while (i < ac && av[i][0] != '-')
			delete_env(av[i++]);
		if (av[i][0] == '-')
		{
			errno = EINVAL;
			print_enno(builtin, av[i]);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
