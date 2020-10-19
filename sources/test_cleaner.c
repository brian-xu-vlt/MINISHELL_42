#include "minishell_bonus.h"

void	debug_waiter_cmd(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	ft_printf("DEBUG WAITER CMD\n");//DEBUG
	while (i < (size_t)cmd->ac)
	{
		ft_printf("CMD->AV[%d] = %s\n", i, cmd->av[i]);//DEBUG
		i++;
	}
}

int	test_cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
}

