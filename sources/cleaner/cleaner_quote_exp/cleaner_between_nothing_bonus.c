#include "minishell_bonus.h"

ssize_t	end_exp(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '?')
		return (FAILURE);
	while (str[i] != '\0')
	{
		if (is_exp_sep(str[i]) == true)
			return (i);
		i++;
	}
	return (i);
}

size_t	handle_exp(size_t i, t_vector *vct_good, char *str)
{
	size_t		tmp_i;
	t_vector	*vct_exp;
	t_vector	*vct_value;
	t_vector	*vct_len2;
	
	vct_exp = vct_new();
	vct_value = vct_new();
	tmp_i = 0;
	tmp_i = end_exp(str + i + 1);
	if ((ssize_t)tmp_i == FAILURE)
	{
		vct_addstr(vct_value, exp_value("?"));
		vct_addstr(vct_good, vct_getstr(vct_value));
		vct_del(&vct_value);
		vct_del(&vct_exp);
		i = i + 2;
		return (i);
	}
	if (tmp_i == 0)
	{
		vct_len2 = vct_new();
		vct_addstr(vct_len2, str + i);
		vct_add(vct_good, vct_getcharat(vct_len2, 0));
		vct_add(vct_good, vct_getcharat(vct_len2, 1));
		i = i + 2;
		vct_del(&vct_value);
		vct_del(&vct_exp);
		vct_del(&vct_len2);
		return (i);
	}
	vct_addstr(vct_exp, str + i + 1);
	vct_cutfrom(vct_exp, vct_getlen(vct_exp) - tmp_i);
	i = i + tmp_i + 1;
	vct_addstr(vct_value, exp_value(vct_getstr(vct_exp)));
	vct_addstr(vct_good, vct_getstr(vct_value));
	vct_del(&vct_value);
	vct_del(&vct_exp);
	return (i);
}
