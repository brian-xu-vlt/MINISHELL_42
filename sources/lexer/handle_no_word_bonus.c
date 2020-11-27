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

	quote_state = false;
	dquote_state = false;
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		ret_parse = true;
		if (c == C_SIMPLE_QUOTE)
			quote_state = !quote_state;
		else if (c == C_QUOTE && quote_state == false)
			dquote_state = !dquote_state;
		if (quote_state == false)
		{
			ret_parse = parse_backslash(input, word, dquote_state);
			if (ret_parse == false)
			{
				if (dquote_state == false && is_end(input) == true)
					break;
			}
			else if (ret_parse == true && vct_getlen(input) != 1 && dquote_state == 1 && quote_state == 0)
				continue ;
			else if (ret_parse == true && vct_getlen(input) != 1 && dquote_state == 0 && quote_state == 1)
				continue ;
			else if (ret_parse == true && vct_getlen(input) == 1 && dquote_state != 1)
			{
				print_set_errno(0, ERR_NEWLINE, NULL, NULL);
				ms_setenv_int(get_env_list(GET), "?", 2, F_OVERWRITE);
				return (FAILURE);
			}
		}
		c = vct_getfirstchar(input);
		vct_add(word, c);
		vct_pop(input);
	}
	return (SUCCESS);
}
