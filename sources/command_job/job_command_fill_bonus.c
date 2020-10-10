#include "minishell_bonus.h"

void	fill_name(char *str, t_cmd *cmd)
{
	char	*cpy_name;

	cpy_name = ft_strjoin(cmd->name, str);
	cmd->name = ft_strjoin(cpy_name, " ");
	free(cpy_name);
}

int	fill_ac(char **av)
{
	int	ac;

	ac = 0;
	while (av[ac] != NULL)
		ac++;
	return (ac);
}
