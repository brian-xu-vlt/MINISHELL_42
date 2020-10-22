#include "minishell_bonus.h"

void	clean_quote(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		if (ft_strchr(cmd->av[i], EXP) == NULL)
		{
			cmd->av[i] = clean_quote_no_exp(cmd->av[i]);
		}
		else
		{
			ft_printf("OH ICI ?\n");//DEBUG
			cmd->av[i] = clean_quote_exp(cmd->av[i]);
		}
		i++;
	}
}

static void	hub_exp_assign(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		ft_printf("cmd->av[%d] = %s\n", i, cmd->av[i]);//DEBUG
		i++;
	}
}

int	cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
	hub_exp_assign(cmd);
}
