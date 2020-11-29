#include "minishell_bonus.h"

static bool parse_backslash(t_vector *input, t_vector *word, bool is_quoting)
{
	const char c = vct_getfirstchar(input);
	const char c_next = vct_getcharat(input, 1);

	if (c != C_BACKSLASH)
		return (false);
	if ((is_quoting == true && (c_next == C_EXP || c_next == C_BACKSLASH ||
			c_next == C_QUOTE))
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

static int	backslash(char c, t_vector *word, t_vector *input, char next_c)
{
	vct_add(word, c);
	vct_pop(input);
	if (next_c == '\0')
	{
		print_set_errno(0, ERR_NEWLINE, NULL, NULL);
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, 2, F_OVERWRITE);
		return (FAILURE);
	}
	vct_add(word, next_c);
	vct_pop(input);
	return (TRUE);
}

static int	is_syntax_error(bool quote_state, bool dquote_state)
{
	if (quote_state == true || dquote_state == true)
	{
		print_set_errno(0, ERR_SYNTAX, NULL, NULL);
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, 2, F_OVERWRITE);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	is_newline_error(bool dquote_state, bool quote_state,
								t_vector *input)
{
	if (dquote_state == false && quote_state == false &&
		is_end(input) == true)
	{
		print_set_errno(0, ERR_NEWLINE, NULL, NULL);
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, 2, F_OVERWRITE);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	handle_quote(char c, bool quote_state, bool dquote_state,
							t_vector *input)
{
	if (quote_state == false && dquote_state == false && (c == C_SPACE ||
			c == C_TAB))
	{
		vct_pop(input);
		return (SUCCESS);
	}
	if (dquote_state == false && quote_state == false && is_end(input) == true)
		return (SUCCESS);
	return (FAILURE);
}

static int	backsl_quote(bool quote_state, bool dquote_state, t_vector *input,
							t_vector *word)
{
	int	ret_parse;

	if (quote_state == false)
	{
		if (vct_getfirstchar(input) == C_BACKSLASH)
			ret_parse = parse_backslash(input, word, dquote_state);
		if (ret_parse == false)
			if (is_newline_error(dquote_state, quote_state, input) == FAILURE)
				return (FAILURE);
	}
	return (SUCCESS);
}

static void	pop_word_input(char c, t_vector *word, t_vector *input)
{
		vct_add(word, c);
		vct_pop(input);
}

int handle_assign_quote(t_vector *in, t_vector *word)
{
	bool q_st;
	bool dq_st;

	q_st = false;
	dq_st = false;
	while (vct_getlen(in) > 0)
	{
		if (vct_getfirstchar(in) == C_BACKSLASH && q_st == false)
		{
			if (backslash(vct_getfirstchar(in), word, in,
					vct_getcharat(in, 1)) == FAILURE)
				return (FAILURE);
			continue ;
		}
		if (vct_getfirstchar(in) == C_SIMPLE_QUOTE && dq_st == false)
			q_st = !q_st;
		else if (vct_getfirstchar(in) == C_QUOTE && q_st == false)
			dq_st = !dq_st;
		if (handle_quote(vct_getfirstchar(in), q_st, dq_st, in) == SUCCESS)
			return (SUCCESS);
		if (backsl_quote(q_st, dq_st, in, word) == FAILURE)
			return (FAILURE);
		pop_word_input(vct_getfirstchar(in), word, in);
	}
	return (is_syntax_error(q_st, dq_st));
}
