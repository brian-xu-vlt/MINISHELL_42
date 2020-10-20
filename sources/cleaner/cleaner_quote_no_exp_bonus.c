#include "minishell_bonus.h"

static enum e_state_quote_no_exp	out(char c)
{
	if (c == C_SIMPLE_QUOTE)
		return (E_IN_SIMPLE_QUOTE);
	if (c == C_QUOTE)
		return (E_IN_DOUBLE_QUOTE);
	return (E_OUT);
}

static enum e_state_quote_no_exp	in_double_quote(char c)
{
	if (c == C_QUOTE)
		return (E_OUT);
	return (E_IN_DOUBLE_QUOTE);
}

static enum e_state_quote_no_exp	in_simple_quote(char c)
{
	if (c == C_SIMPLE_QUOTE)
		return (E_OUT);
	return (E_IN_SIMPLE_QUOTE);
}

static bool	is_pop_char(int old_state, enum e_state_quote_no_exp state)
{
	if ((old_state == FAILURE && state == E_IN_SIMPLE_QUOTE) ||
			(old_state == FAILURE && state == E_IN_DOUBLE_QUOTE) ||
			(old_state == E_IN_DOUBLE_QUOTE && state == E_OUT) ||
			(old_state == E_IN_SIMPLE_QUOTE && state == E_OUT) ||
			(old_state == E_OUT && state == E_IN_DOUBLE_QUOTE) ||
			(old_state == E_OUT && state == E_IN_SIMPLE_QUOTE))
		return (true);
	return (false);
}

char	*clean_quote_no_exp(char *str)
{
	t_vector					*vct_good;
	t_state_quote_no_exp		function_state[] = {in_simple_quote,
		in_double_quote, out};
	enum e_state_quote_no_exp	state;
	size_t						i;
	int							old_state;

	vct_good = vct_new();
	state = E_OUT;
	i = 0;
	old_state = FAILURE;
	while (str[i] != '\0')
	{
		state = function_state[state](str[i]);
		if (is_pop_char(old_state, state) == false)
			vct_add(vct_good, str[i]);
		old_state = state;
		i++;
	}
	str = vct_getstr(vct_good);
	return (str);
}
