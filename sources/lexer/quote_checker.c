/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:44:55 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:44:56 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static enum e_state	squote_state(t_vector *input)
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

static int			process_quote_checker(enum e_state state, t_vector *input)
{
	if ((state == E_STATE_STRING || state == E_STATE_DQUOTE) &&
			vct_getfirstchar(input) == C_BACKSLASH)
	{
		vct_pop(input);
		vct_pop(input);
		return (CONTINUE);
	}
	return (SUCCESS);
}

int					quote_checker(char *str)
{
	static t_state	function_state[] = {string_state, squote_state,
											dquote_state};
	enum e_state	state;
	t_vector		*input;

	input = safe_vct_new();
	state = E_STATE_STRING;
	safe_vct_addstr(input, str);
	while (state != E_STATE_END)
	{
		if (process_quote_checker(state, input) == CONTINUE)
			continue;
		state = function_state[state](input);
		if (state == E_STATE_ERROR)
			break ;
		vct_pop(input);
	}
	vct_del(&input);
	if (state != E_STATE_END)
	{
		vct_del(&input);
		return (FAILURE);
	}
	vct_del(&input);
	return (SUCCESS);
}
