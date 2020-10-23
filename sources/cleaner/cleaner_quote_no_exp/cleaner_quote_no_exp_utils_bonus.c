#include "minishell_bonus.h"

bool	is_only_quote(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != C_QUOTE && str[i] != C_SIMPLE_QUOTE)
			return (false);
		i++;
	}
	return (true);
}

bool	is_clean_command(char *str)
{
	char	*clean_cmd[NB_CLEAN_COMMAND] = {"echo", "export", "unset", "env",
											"exit"};
	size_t	i;

	i = 0;
	while (i < NB_CLEAN_COMMAND)
	{
		if (ft_strequ(str, clean_cmd[i]) == TRUE)
			return (true);
		i++;
	}
	return (false);
}
