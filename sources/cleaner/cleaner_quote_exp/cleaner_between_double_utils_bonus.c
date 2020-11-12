#include "minishell_bonus.h"

int process_quote(char *str, size_t i, t_vector *vct_good, int flag)
{
	size_t end_double;

	end_double = end_quote(str, i, flag);
	if (flag == E_DOUBLE)
		handle_double(str, i, end_double, vct_good);
	if (flag == E_SIMPLE)
		handle_simple(str, i, end_double, vct_good);
	i = i + end_double;
	return (i);
}

int process_exp(char *str, size_t i, t_vector *vct_good, size_t tmp_i)
{
	if (i != tmp_i)
	{
		tmp_i = handle_exp(i, vct_good, str);
		if (i + tmp_i >= ft_strlen(str))
			return (FAILURE);
		i = i + tmp_i;
		return (i);
	}
	return (i);
}

int process_exp_del(char *str, size_t i, t_vector *vct_good,
						   size_t tmp_i)
{
	tmp_i = handle_exp_del(str + i, vct_good, E_NOTHING);
	if (i + tmp_i == ft_strlen(str))
		return (FAILURE);
	i = i + tmp_i;
	return (i);
}
