#include "minishell_bonus.h"

int	set_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "set";
	static const char	*usage = "set: usage: set\n";

	if (ft_strequ(av[0], (char *)builtin) == FALSE || av == NULL)
		return (0);
	errno = 0;
	if (ac > 1)
	{
		print_invalid_option(builtin, av[1], usage);
		return (2);
	}
	if (ac == 1)
		print_export_output(get_env_list(GET), F_SET_OUTPUT);
	export_envp(envp);
	if (errno == EINVAL)
		return (1);
	return (0);
}
