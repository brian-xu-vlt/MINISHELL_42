#include "minishell_bonus.h"

static bool	parse_backslash(t_vector *input, t_vector *word, bool is_quoting)
{
	const char c = vct_getfirstchar(input);
	const char c_next = vct_getcharat(input, 1);

	if (c != C_BACKSLASH)
		return (false);
	if ((is_quoting == true && (c_next == C_EXP || c_next == C_BACKSLASH ||
			c_next == C_QUOTE)) || is_quoting == false)
	{
		if (is_quoting == true)
		{
			vct_add(word, c);
			vct_pop(input);
		}
		return (true);
	}
	return (false);
}

static int	process_state(t_vector *input, t_vector *word)
{
	char		c;
	static bool quote_state = false;
	static bool dquote_state = false;

	c = vct_getfirstchar(input);
	if (c == C_SIMPLE_QUOTE)
		quote_state = !quote_state;
	else if (c == C_QUOTE)
		dquote_state = !dquote_state;
	if (quote_state == false)
	{
		if (parse_backslash(input, word, dquote_state) == false)
			if (dquote_state == false && is_end(input) == true)
				return (BREAK);
	}
	return (SUCCESS);
}

int			handle_assign_quote(t_vector *input, t_vector *word)
{
	char c;

	while (vct_getlen(input) > 0)
	{
		if (process_state(input, word) == BREAK)
			break ;
		c = vct_getfirstchar(input);
		vct_add(word, c);
		if (c == C_BACKSLASH && vct_getlen(input) == 1)
		{
			print_set_errno(0, ERR_NEWLINE, NULL, NULL);
			ms_setenv_int(get_env_list(GET), "?", 2, F_OVERWRITE | F_EXPORT);
			return (FAILURE);
		}
		vct_pop(input);
	}
	return (SUCCESS);
}
