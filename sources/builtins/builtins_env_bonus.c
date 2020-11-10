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

static void	export_loop(int ac, char **av, const char *builtin)
{
	int			i;

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

static void	export_envp(char **envp)
{
	int			i;

	i = 0;
	if (envp == NULL)
		return ;
	while (envp != NULL && envp[i] != NULL)
		export_env(get_env_list(GET), envp[i++]);
}

int	export_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "export";
(void)envp;

	errno = 0;
	if (ft_strequ(av[0], (char *)builtin) == TRUE && ac > 1)
	{
		if (av[1][0] == '-')
		{
			print_set_errno(0, " Invalid option", builtin, av[1]);
			return (2);
		}
		else
			export_loop(ac, av, builtin);
		if (errno == EINVAL)
			return (1);
	}
	if (ft_strequ(av[0], (char *)builtin) == TRUE && ac == 1)
		print_export_output(get_env_list(GET));
	export_envp(envp);
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
		i = 1;
		while (i < ac)
		{
			if (av[i][0] == '-')
				print_set_errno(EINVAL, NULL, builtin, av[i]);
		//	else if (ft_isalpha(av[i][0]) == TRUE)
			else
				unset_env(get_env_list(GET), av[i]);
			i++;
		}
	}
	return (SUCCESS);
}
