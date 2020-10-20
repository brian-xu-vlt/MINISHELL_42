#include "minishell_bonus.h"

static char *clean_quote_exp(char *str)
{
	return (str);
}

static char	*clean_quote_no_exp(char *str)
{
	return (str);
}

void	clean_quote(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		if (ft_strchr(cmd->av[i], EXP) == NULL)
			cmd->av[i] = clean_quote_no_exp(cmd->av[i]);
		else
			cmd->av[i] = clean_quote_exp(cmd->av[i]);
		i++;
	}
}

int	cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
}
