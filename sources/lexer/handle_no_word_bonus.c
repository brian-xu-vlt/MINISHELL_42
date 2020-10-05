#include "minishell_bonus.h"

static enum	e_state	squote_state(t_vector *input)
{
	if (is_simplequote(input) == true)
		return (E_STATE_STRING);
	else if (vct_getfirstchar(input) == '\0')
		return (E_STATE_ERROR);
	return (E_STATE_SQUOTE);
}

static enum e_state	dquote_state(t_vector *input)
{
	if (is_doublequote(input) == true)
		return (E_STATE_STRING);
	else if (vct_getfirstchar(input) == '\0')
		return (E_STATE_ERROR);
	return (E_STATE_DQUOTE);
}

static enum e_state	string_state(t_vector *input)
{
	if (is_end(input) == true)
		return (E_STATE_END);
	else if (is_simplequote(input) == true)
		return (E_STATE_SQUOTE);
	else if (is_doublequote(input) == true)
		return (E_STATE_DQUOTE);
	return (E_STATE_STRING);
}

int			quote_checker(char *str)
{
	t_state			function_state[] = {string_state, squote_state,
		dquote_state};
	enum e_state	state;
	//enum e_state past_state = E_STATE_STRING;
	//const char	*debug_error[] = {"STRING", "SQUOTE", "DQUOTE", "END", "ERROR"};
	t_vector		*input;

	input = vct_new();
	state = E_STATE_STRING;
	vct_addstr(input, str);
	//ft_printf("STR QUOTE CHECKER = %s\n", str);//DEBUG
	while (state != E_STATE_END)
	{
		//past_state = state;
		//ft_printf(" ->%s \n", debug_error[state]);
		state = function_state[state](input);
		if (state == E_STATE_ERROR)
			break ;
		vct_pop(input);
	}
	vct_del(&input);
	//ft_printf("END ->%s \n", debug_error[state]);
	if (state != E_STATE_END)
	{
		vct_del(&input);
		//ft_printf("\033[31mError on -> %s\n\033[0m", debug_error[past_state]);
		return (FAILURE);
	}
	vct_del(&input);
	return (SUCCESS);
}

int			handle_assign_quote(t_vector *input, t_vector *word)
{
	char	c;
	bool	quote_state;
	bool	dquote_state;

	quote_state = false;
	dquote_state = false;
	c = vct_getfirstchar(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (c == C_SIMPLE_QUOTE)
			quote_state = !quote_state;
		else if (c == C_QUOTE)
			dquote_state = !dquote_state;
		if (quote_state == false && dquote_state == false
				&& is_end(input) == true)
			break ;
		vct_add(word, c);
		vct_pop(input);
	}
	return (SUCCESS);
}
