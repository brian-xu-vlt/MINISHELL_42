#include "minishell_bonus.h"

char *exp_value(char *str)
{
	t_vector *vct;

	vct = get_env_value_vct(get_env_list(GET), str);
	return (vct_getstr(vct));
}

bool is_exp_sep(char c)
{
	return (ft_isalnum(c) == false && ft_strchr(EXP_DEL_EXCEPTION, c) == NULL);
}

int handle_backslash_double(char c, t_vector *input)
{
	vct_pop(input);
	c = vct_getfirstchar(input);
	if (c == '\0')
	{
		print_set_errno(0, "syntax error : missing newline", NULL, NULL);
		return (FAILURE);
	}
	return (SUCCESS);
}

int handle_backslash_nothing(t_vector *input, t_vector *output, char c)
{
	vct_pop(input);
	if (c == '\0')
	{
		print_set_errno(0, "syntax error : missing newline", NULL, NULL);
		return (FAILURE);
	}
	vct_add(output, vct_getfirstchar(input));
	vct_pop(input);
	return (SUCCESS);
}
