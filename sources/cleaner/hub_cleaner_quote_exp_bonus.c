#include "minishell_bonus.h"

static enum e_between	is_between(char *str)
{
	t_vector	*vct;
	t_vector	*vct_cpy;
	ssize_t	nb_simple;
	ssize_t	nb_double;

	vct = vct_new();
	vct_cpy = vct_new();
	vct_addstr(vct, str);
	vct_addstr(vct_cpy, str);
	nb_simple = vct_nbchar(vct, SIMPLE_QUOTE);
	nb_double = vct_nbchar(vct_cpy, QUOTE);
	vct_del(&vct);
	vct_del(&vct_cpy);
	if (nb_double != 0 && nb_simple == 0)
		return (E_DOUBLE);
	else if (nb_simple != 0 && nb_double == 0)
		return (E_SIMPLE);
	return (nb_double != 0 && nb_simple != 0 ? E_BOTH : E_NOTHING);
}

static char	*hub_between_function(enum e_between between, char *str)
{
	char	*good_str;

	if (between == E_NOTHING)
		good_str = between_nothing(str);
	else if (between == E_SIMPLE)
		good_str = between_simple(str);
	else if (between == E_DOUBLE)
		good_str = between_double(str);
	else
		good_str = between_both(str);
	return (good_str);
}

char	*clean_quote_exp(char *str)
{
	t_vector		*vct_cmd;
	enum e_between	between;
	char			*good_str;

	vct_cmd = vct_new();
	vct_addstr(vct_cmd, str);
	between = is_between(str);
	good_str = hub_between_function(between, str);
	vct_del(&vct_cmd);
	return (str);
}
