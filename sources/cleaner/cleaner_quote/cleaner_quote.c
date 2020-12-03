/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:43 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:16:44 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		parse_simple_quote(t_vector *input, t_vector *output)
{
	char c;

	vct_pop(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (c == C_BACKSLASH && vct_getcharat(input, 1) == C_QUOTE)
		{
			safe_vct_add(output, c);
			vct_pop(input);
			c = vct_getfirstchar(input);
			safe_vct_add(output, c);
			vct_pop(input);
			continue ;
		}
		if (c == C_SIMPLE_QUOTE)
			break ;
		safe_vct_add(output, c);
		vct_pop(input);
	}
	vct_pop(input);
}

static int	handle_backslash(char c, t_vector *input, t_vector *output)
{
	vct_pop(input);
	c = vct_getfirstchar(input);
	safe_vct_add(output, c);
	vct_pop(input);
	return (SUCCESS);
}

static int	handle_char(char c, t_vector *input, t_vector *output)
{
	int flag;

	flag = 0;
	if (c == C_BACKSLASH)
		return (handle_backslash(c, input, output));
	else if (c == C_SIMPLE_QUOTE)
	{
		flag = flag | F_SQUOTE;
		parse_simple_quote(input, output);
		if (vct_getlen(input) == 0)
			return (SUCCESS);
	}
	else if (c == C_QUOTE)
	{
		if (parse_double_quote(input, output) == FAILURE)
			return (FAILURE);
		return (flag = flag | F_DQUOTE);
	}
	else if (c == C_EXPORT)
		return (is_export(c, input, output));
	else
		pop_input_output(c, input, output);
	return (flag);
}

int			process_clean_quote(t_vector *input, t_vector *output)
{
	char	c;
	int		flag;

	flag = 0;
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		flag = handle_char(c, input, output);
		if (flag == FAILURE)
			return (FAILURE);
	}
	if (flag == 8 && vct_getlen(output) == 0)
		return (2);
	if ((flag & F_SQUOTE || flag & F_DQUOTE) && vct_getlen(output) == 0)
	{
		vct_clear(output);
		safe_vct_add(output, '\0');
	}
	return (SUCCESS);
}
