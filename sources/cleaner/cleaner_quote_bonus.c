#include "minishell_bonus.h"

void	process_clean_command_quote(t_cmd *cmd, size_t i)
{
	if (ft_strchr(cmd->av[i], EXP) == NULL)
		cmd->av[i] = clean_quote_no_exp(cmd->av[i]);
	else
		cmd->av[i] = clean_quote_exp(cmd->av[i]);
}

void	iter_clean_quote(t_cmd *cmd, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		process_clean_command_quote(cmd, i);
		i++;
	}
}
