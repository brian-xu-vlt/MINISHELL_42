#include "minishell_bonus.h"

static bool	is_valid_identifier(char *av_to_test)
{
 return (verif_assign_cmd(av_to_test) == false
		&& (ft_isalpha(*av_to_test) == true || *av_to_test == '_'));
}

static void	export_loop(char **av, const char *builtin)
{
	int					i;

	i = 1;
	while (av != NULL && av[i] != NULL)
	{
		if (is_valid_identifier(av[i]) == TRUE)
			export_env(get_env_list(GET), av[i]);
		else
			print_invalid_identifier(builtin, av[i]);
		i++;
	}
}

void	export_envp(char **envp)
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

	if (ft_strequ(av[0], (char *)builtin) == FALSE || av == NULL)
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
			export_loop(av, builtin);
	}
	if (ac == 1)
		print_export_output(get_env_list(GET));
	export_envp(envp);
	if (errno == EINVAL)
		return (1);
	return (SUCCESS);
}
