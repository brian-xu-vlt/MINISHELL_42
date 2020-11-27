#include "minishell_bonus.h"

static bool parse_backslash(t_vector *input, t_vector *word, bool is_quoting)
{
	const char c = vct_getfirstchar(input);
	const char c_next = vct_getcharat(input, 1);

	if (c != '\\')
		return (false);
	if ((is_quoting == true && (c_next == '$' || c_next == '\\' || c_next == '\"'))
			|| is_quoting == false)
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

int handle_assign_quote(t_vector *input, t_vector *word)
{
	char c;
	bool quote_state;
	bool dquote_state;
	int	ret_parse;
	bool	is_backsl;
	char	next_c;

	quote_state = false;
	dquote_state = false;
	is_backsl = false;
	while (vct_getlen(input) > 0)
	{
		is_backsl = false;
		c = vct_getfirstchar(input);
		next_c = vct_getcharat(input, 1);
		if (c == C_BACKSLASH)
		{
			is_backsl = true;
			vct_add(word, c);
			vct_pop(input);
			continue ;
		}
		ret_parse = true;
		if (c == C_SIMPLE_QUOTE && is_backsl == false)
			quote_state = !quote_state;
		else if (c == C_QUOTE && quote_state == false && is_backsl == false) 
			dquote_state = !dquote_state;
		if (dquote_state == false && quote_state == false && (c == C_SPACE || c == C_TAB)) 
		{
			vct_pop(input);
			return (SUCCESS);
		}
		if (quote_state == false)
		{
			if (c == C_BACKSLASH)
				ret_parse = parse_backslash(input, word, dquote_state);
			if (ret_parse == false)
			{
				if (dquote_state == false && quote_state == false && is_end(input) == true)
				{
					print_set_errno(0, ERR_NEWLINE, NULL, NULL);
					ms_setenv_int(get_env_list(GET), "?", 2, F_OVERWRITE);
					return (FAILURE);
				}
			}
		}
		vct_add(word, c);
		vct_pop(input);
	}
	return (SUCCESS);
}
