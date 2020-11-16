#include "minishell_bonus.h"

int	count_clean_exp(char **av, size_t size)
{
	size_t	i;
	size_t	clean_exp;

	i = 0;
	clean_exp = 0;
	while (i < size)
	{
		if (ft_strchr(av[i], EXP) != NULL)
			clean_exp++;
		i++;
	}
	return (clean_exp);
}
