#include "minishell_bonus.h"

bool is_exp_sep(char c)
{
	return (ft_isalnum(c) == false && ft_strchr(EXP_DEL_EXCEPTION, c) == NULL);
}

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
		if (good_str[in] == '\\'
			&& (good_str[in + 1] == '$'
				|| good_str[in + 1] == '\\'
				|| good_str[in + 1] == '\0'
				|| good_str[in + 1] == '\"'))
		{
			if ((good_str[in + 1] == '\"'
				&& (good_str[in + 2] == '\0' || ft_strchr(good_str + in + 2, '\"') == NULL))
				|| good_str[in + 1] == '\0')
			{
				ft_printf("That's an eror !\n");
				exit(1);
			}
			vct_add(vct_good, good_str[in + 1]);
			in += 2;
			continue;
		}
		if (in + 1 < ft_strlen(good_str) && good_str[in] == '$'
				&& good_str[in + 1] == '?')
		{
			in = handle_exp(in, vct_good, good_str);
			continue ;
		}
		if (good_str[in] != EXP || (good_str[in] == EXP
				&& (in == ft_strlen(good_str) - 1
				|| is_exp_sep(good_str[in + 1]) == true)))
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
		if (str[i] == EXP && i + 1 <= ft_strlen(str) && str[i + 1] != C_QUOTE)
		{
			i = handle_exp(i, vct_good, str);
			continue ;
		}
		if (str[i] != EXP && i + 1 <= ft_strlen(str) && str[i + 1] != C_QUOTE)
			vct_add(vct_good, str[i]);
		i++;
	}
}
