/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:35 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:16:36 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		parse_expansion(t_vector *input, t_vector *output)
{
	t_vector	*expansion;
	char		*expansion_value;
	char		c;
	size_t		i;

	expansion = safe_vct_new();
	vct_pop(input);
	i = 0;
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (is_exp_sep(c) && c != QUESTION_MARK)
			break ;
		safe_vct_add(expansion, c);
		vct_pop(input);
		i++;
	}
	if (vct_getlen(expansion) == 0)
		safe_vct_add(output, C_EXPORT);
	else
	{
		expansion_value = exp_value(vct_getstr(expansion));
		safe_vct_addstr(output, expansion_value);
	}
	vct_del(&expansion);
}

static int	handle_export(char c, t_vector *input, t_vector *output)
{
	if (c == C_EXPORT && vct_getlen(input) != 1 &&
		(vct_getcharat(input, 1) == C_SIMPLE_QUOTE ||
		vct_getcharat(input, 1) == C_QUOTE))
	{
		vct_pop(input);
		return (SUCCESS);
	}
	if (c == C_EXPORT && vct_getlen(input) != 1 &&
		is_exp_sep(vct_getcharat(input, 1)) == true &&
		vct_getcharat(input, 1) != QUESTION_MARK)
	{
		if (vct_getcharat(input, 1) == C_BACKSLASH)
		{
			safe_vct_add(output, c);
			vct_pop(input);
			return (SUCCESS);
		}
		safe_vct_add(output, c);
		vct_pop(input);
		pop_input(input, output);
		return (SUCCESS);
	}
	return (FAILURE);
}

int			is_export(char c, t_vector *input, t_vector *output)
{
	int flag;

	flag = 0;
	if (handle_export(c, input, output) == SUCCESS)
		return (SUCCESS);
	parse_expansion(input, output);
	if (vct_getfirstchar(output) == C_EXP && vct_getlen(input) != 0 &&
		vct_getfirstchar(input) != C_BACKSLASH)
		vct_pop(output);
	return (flag = flag | F_EXP);
}
