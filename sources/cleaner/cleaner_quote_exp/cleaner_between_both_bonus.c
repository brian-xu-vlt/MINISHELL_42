#include "minishell_bonus.h"

static size_t	process_simple(char *str, size_t i, t_vector *vct_good)
{
	size_t		end_simple;

	end_simple = 0;
	end_simple = end_quote(str, i, E_SIMPLE);
	handle_simple(str, i, end_simple, vct_good);
	return (end_simple);
}

static size_t	process_double(char *str, size_t i, t_vector *vct_good)
{
	size_t		end_double;

	end_double = 0;
	end_double = end_quote(str, i, E_DOUBLE);
	handle_double(str, i, end_double, vct_good);
	return (end_double);
}

void			process_between_both(char *str, t_vector *vct_good)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == C_QUOTE)
		{
			i = i + process_double(str, i, vct_good);
			continue ;
		}
		if (str[i] == C_SIMPLE_QUOTE)
		{
			i = i + process_simple(str, i, vct_good);
			continue ;
		}
		if (str[i] == EXP && i + 1 <= ft_strlen(str) && str[i + 1] != C_QUOTE &&
			str[i + 1] != C_SIMPLE_QUOTE)
		{
			i = handle_exp(i, vct_good, str);
			continue ;
		}
		if (str[i] != EXP && i + 1 <= ft_strlen(str) && str[i + 1] != C_SIMPLE_QUOTE
			&& str[i + 1] != C_QUOTE)
			vct_add(vct_good, str[i]);
		i++;
	}
}
