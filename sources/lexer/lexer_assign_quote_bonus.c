#include "minishell_bonus.h"

/////////////////TOOLS//////////////////////

static bool	stop_assign_str(t_vector *input)
{
	t_vector *cpy_input;

	cpy_input = vct_new();
	vct_cpy(cpy_input, input);
	vct_cutfrom(cpy_input, vct_getlen(cpy_input) - 2);
	return (vct_getlen(input) == 1
				|| ft_strequ(vct_getstr(cpy_input), OR) == TRUE
				|| ft_strequ(vct_getstr(cpy_input), AND) == TRUE
				|| ft_strequ(vct_getstr(cpy_input), DOUBLE_GREATER) == TRUE ?
				true : false);
				
}

static bool	stop_assign_char(char c)
{
	return (c == '\0' || c == C_SEPARATOR || c == C_PIPE || c == C_LESS_THAN
				|| c == C_GREATER_THAN || c == C_SPACE ? true : false);
}

static bool	is_end(t_vector *input)
{
	const char	c = vct_getfirstchar(input);

	return (stop_assign_char(c) == true || stop_assign_str(input) == true);
}

static bool	is_simplequote(t_vector *input)
{
	const char	c = vct_getfirstchar(input);

	return (c == C_SIMPLE_QUOTE);
}

static bool	is_doublequote(t_vector *input)
{
	const char	c = vct_getfirstchar(input);

	return (c == C_QUOTE);
}

/////////////////STATE////////////////////

static enum e_state	squote_state(t_vector *input)
{
	if (is_end(input) == true)
		return (E_STATE_ERROR);
	else if (is_simplequote(input) == true)
		return (E_STATE_STRING);
	return (E_STATE_SQUOTE);
}

static enum e_state	dquote_state(t_vector *input)
{
	if (is_end(input) == true)
		return (E_STATE_ERROR);
	else if (is_doublequote(input) == true)
		return (E_STATE_STRING);
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

int	quote_checker(char *str)
{
	t_state	function_state[] = {string_state, squote_state, dquote_state};
	enum e_state state = E_STATE_STRING;
	enum e_state past_state = E_STATE_STRING;
	const char	*debug_error[] = {"STRING", "SQUOTE", "DQUOTE", "END", "ERROR"};
	t_vector	*input = vct_new();
	
	vct_addstr(input, str);
	while (vct_getlen(input) > 0)
	{
		past_state = state;
		ft_printf("%c", vct_getfirstchar(input));
		ft_printf(" ->%s \n", debug_error[state]);
		state = function_state[state](input);
		if (state == E_STATE_END)
			break ;
		else if (state == E_STATE_ERROR)
		{
			ft_printf("Error on -> %s\n", debug_error[past_state]);
			vct_del(&input);
			return (FAILURE);
		}
		vct_pop(input);
	}
	ft_printf("END ->%s \n", debug_error[state]);
	vct_del(&input);
	return (SUCCESS);
}

int	handle_assign_quote(t_vector *input, t_vector *word)
{
	while (vct_getlen(input) > 0 && is_end(input) == false)
	{
		vct_add(word, vct_getfirstchar(input));
		vct_pop(input);
	}
	return (SUCCESS);
}
