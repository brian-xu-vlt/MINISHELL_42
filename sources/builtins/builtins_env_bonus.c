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
