#include "minishell_bonus.h"

static bool	stop_assign_str(t_vector *input)
{
	t_vector	*cpy_input;
	bool		ret;

	cpy_input = vct_new();
	vct_cpy(cpy_input, input);
	vct_cutfrom(cpy_input, vct_getlen(cpy_input) - 2);
	ret = false;
	if (ft_strequ(vct_getstr(cpy_input), OR) == TRUE
			|| ft_strequ(vct_getstr(cpy_input), AND) == TRUE
			|| ft_strequ(vct_getstr(cpy_input), DOUBLE_GREATER) == TRUE)
		ret = true;
	vct_del(&cpy_input);
	return (ret);
}

static bool	stop_assign_char(char c)
{
	return (c == '\0' || c == C_SEPARATOR || c == C_PIPE || c == C_LESS_THAN
				|| c == C_GREATER_THAN || c == C_SPACE || c == C_TAB
				? true : false);
}

bool		is_end(t_vector *input)
{
	const char	c = vct_getfirstchar(input);

	return (stop_assign_char(c) == true || stop_assign_str(input) == true);
}

bool		is_simplequote(t_vector *input)
{
	const char	c = vct_getfirstchar(input);

	return (c == C_SIMPLE_QUOTE);
}

bool		is_doublequote(t_vector *input)
{
	const char	c = vct_getfirstchar(input);

	return (c == C_QUOTE);
}