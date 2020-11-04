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

int	*fill_tab_clean_exp(int *tab_clean_exp, char **av, size_t size,
									int clean_exp)
{
	size_t	i;
	size_t	i_exp;

	i = 0;
	i_exp = 0;	
	while (i < size)	
	{
		if (ft_strchr(av[i], EXP) != NULL)
		{
			if (clean_exp != 0)
			{
				tab_clean_exp[i_exp] = i;
				i_exp++;
			}
			av[i] = clean_quote_exp(av[i]);
		}
		i++;
	}
	return (tab_clean_exp);
}
