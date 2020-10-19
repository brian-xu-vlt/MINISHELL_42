#include "minishell_bonus.h"

void	put_env(char *env_name, t_vector *env_value)
{
	ft_putstr_fd(env_name, STDERR_FILENO);
	if (env_value != NULL)
		ft_printf("=%s", vct_getstr(env_value));
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_env(void)
{
	char	**envp;
	int		i;
	i = 0;

	envp = get_envp();
	while (envp[i] != NULL)
	{
		ft_putstr_fd(envp[i], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		i++;
	}
	free_envp(envp);
}
