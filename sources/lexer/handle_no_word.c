/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:43:58 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:43:59 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int			is_newline_error(bool dquote_state, bool quote_state,
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

static void	pop_word_input(char c, t_vector *word, t_vector *input)
{
	safe_vct_add(word, c);
	vct_pop(input);
}

int			handle_assign_quote(t_vector *in, t_vector *word)
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
