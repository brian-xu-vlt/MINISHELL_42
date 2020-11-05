#include "minishell_bonus.h"

void	handle_simple(char *str, size_t i, size_t end_simple,
						t_vector *vct_good)
{
	t_vector	*vct_simple;
	char		*good_str;

	vct_simple = vct_new();
	vct_addstr(vct_simple, str + i);
	vct_cutfrom(vct_simple, vct_getlen(vct_simple) - end_simple);
	vct_pop(vct_simple);
	vct_cut(vct_simple);
	good_str = ft_strdup(vct_getstr(vct_simple));
	vct_addstr(vct_good, good_str);
	vct_del(&vct_simple);
	free(good_str);
}

size_t	end_quote(char *str, size_t i, enum e_between quote)
{
	size_t		end_quote;
	char		*new_str;

	new_str = str + i;
	end_quote = 1;
	while (new_str[end_quote] != '\0')
	{
		if (new_str[end_quote] == (quote == E_SIMPLE ?
				C_SIMPLE_QUOTE : C_QUOTE))
		{
			end_quote++;
			return (end_quote);
		}
		end_quote++;
	}
	return (0);
}

void	process_between_simple(char *str, t_vector *vct_good)
{
	size_t	i;
	size_t	end_simple;

	i = 0;
	end_simple = 0;
	while (str[i] != '\0')
	{
		if (str[i] == C_SIMPLE_QUOTE)
		{
			end_simple = end_quote(str, i, E_SIMPLE);
			handle_simple(str, i, end_simple, vct_good);
			i = i + end_simple;
			continue ;
		}
		if (str[i] == EXP)
		{
			i = handle_exp(i, vct_good, str);
			continue ;
		}
		vct_add(vct_good, str[i]);
		i++;
	}
}
