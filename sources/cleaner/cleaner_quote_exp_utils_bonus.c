#include "minishell_bonus.h"

bool	is_del(char c)
{
	size_t	i;

	i = 0;
	while (i < NB_DEL)
	{
		if (c == DEL[i])
		{
			ft_printf("DEL IS TRUE\n");//DEBUG
			return (true);
		}
		i++;
	}
	return (false);
}
