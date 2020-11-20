#include "minishell_bonus.h"

static void	print_envp(char **envp)
{
	int			i;

	i = 0;
	while (envp != NULL && envp[i] != NULL)
		ft_printf("%s\n", envp[i++]);
}

int	env_builtin(int ac, char **av, char **envp)
{
	const char	*builtin = "env";

	print_envp(envp);
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
	int					i;

	i = 1;
	while (i < ac)
	{
		if (verif_assign_cmd(av[i]) == false)
			export_env(get_env_list(GET), av[i]);
		else
			print_invalid_identifier(builtin, av[i]);
		i++;
	}
}

static void	export_envp(char **envp)
{
	int					i;

	i = 0;
	if (envp == NULL)
		return ;
	while (envp != NULL && envp[i] != NULL)
		export_env(get_env_list(GET), envp[i++]);
}

int	export_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "export";
	static const char	*usage = "export: usage: export [name[=value] ...]\n";

	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	errno = 0;
	if (ac > 1)
	{
		if (av[1][0] == '-')
		{
			print_invalid_option(builtin, av[1], usage);
			return (2);
		}
		else
			export_loop(ac, av, builtin);
	}
	if (ac == 1)
		print_export_output(get_env_list(GET));
	export_envp(envp);
	if (errno == EINVAL)
		return (1);
	return (SUCCESS);
}

int	unset_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "unset";
	static const char	*usage = "unset: usage: unset [name ...]\n";
	int					i;

	errno = 0;
	export_envp(envp);
	if (ac == 1 || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else
	{
		i = 1;
		while (i < ac)
		{
			if (av[i][0] == '-' && i >= 2)
				print_invalid_identifier(builtin, av[i]);
			else if (av[i][0] == '-')
			{
				print_invalid_option(builtin, av[i], usage);
				return (2);
			}
			else if (ft_isalpha(*av[i]) == TRUE)
				unset_env(get_env_list(GET), av[i]);
			i++;
		}
	}
	if (errno != 0)
		return (1);
	return (SUCCESS);
}
