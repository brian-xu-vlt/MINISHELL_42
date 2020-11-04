#include "minishell_bonus.h"

void	handle_double(char *str, size_t i, size_t end_simple,
						t_vector *vct_good)
{
	t_vector	*vct_simple;
	char		*good_str;
	size_t		in;

	vct_simple = vct_new();
	vct_addstr(vct_simple, str + i);
	vct_cutfrom(vct_simple, vct_getlen(vct_simple) - end_simple);
	vct_pop(vct_simple);
	vct_cut(vct_simple);
	in = 0;
	good_str = ft_strdup(vct_getstr(vct_simple));
	while (good_str[in] != '\0')
	{
		if (good_str[in] != EXP || (good_str[in] == EXP
				&& in == ft_strlen(good_str) - 1))
			vct_add(vct_good, good_str[in]);
		else if (good_str[in] == EXP)
		{
			in = handle_exp(in, vct_good, good_str);
			continue ;
		}
		in++;
	}
	vct_del(&vct_simple);
	free(good_str);
}

void	process_between_double(char *str, t_vector *vct_good)
{
	size_t	i;
	size_t	end_double;

	i = 0;
	end_double = 0;
	while (str[i] != '\0')
	{
		if (str[i] == C_QUOTE)
		{
			end_double = end_quote(str, i, E_DOUBLE);
			handle_double(str, i, end_double, vct_good);
			i = i + end_double;
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
