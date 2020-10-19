#include "minishell_bonus.h"

char	*clean_quote_no_exp(char *str)
{
	return (NULL);
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
			ft_printf("EXP\n");//DEBUG
		i++;
	}
}
