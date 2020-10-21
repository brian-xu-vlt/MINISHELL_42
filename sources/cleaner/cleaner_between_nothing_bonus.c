#include "minishell_bonus.h"

size_t	handle_exp(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_del(str[i]) == true)
			return (i);
		i++;
	}
	return (i);
}
