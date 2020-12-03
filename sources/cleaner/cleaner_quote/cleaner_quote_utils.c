/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_quote_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:56 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:16:57 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exp_value(char *str)
{
	t_vector *vct;

	vct = get_env_value_vct(get_env_list(GET), str);
	return (vct_getstr(vct));
}

bool	is_exp_sep(char c)
{
	return (ft_isalnum(c) == false && ft_strchr(EXP_DEL_EXCEPTION, c) == NULL);
}

int		handle_backslash_double(char c, t_vector *input)
{
	vct_pop(input);
	c = vct_getfirstchar(input);
	if (c == '\0')
	{
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, 2, F_OVERWRITE);
		print_set_errno(0, ERR_NEWLINE, NULL, NULL);
		return (FAILURE);
	}
	return (SUCCESS);
}

int		handle_backslash_nothing(t_vector *input, t_vector *output, char c)
{
	vct_pop(input);
	if (c == '\0')
	{
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, 2, F_OVERWRITE);
		print_set_errno(0, ERR_NEWLINE, NULL, NULL);
		return (FAILURE);
	}
	safe_vct_add(output, vct_getfirstchar(input));
	vct_pop(input);
	return (SUCCESS);
}

int		is_backslash(char c, char next_c, t_vector *input)
{
	if (c == C_BACKSLASH && (next_c == C_EXP || next_c == C_QUOTE ||
		next_c == C_BACKSLASH))
	{
		if (handle_backslash_double(c, input) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
