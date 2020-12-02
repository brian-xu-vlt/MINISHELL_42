#include "minishell.h"

static int	process_parse_double_quote(char c, char next_c, t_vector *input,
										t_vector *output)
{
	if (c == C_BACKSLASH && next_c == C_QUOTE)
	{
		vct_pop(input);
		safe_vct_add(output, next_c);
		return (SUCCESS);
	}
	if (is_backslash(c, next_c, input) == FAILURE)
		return (FAILURE);
	else if (c == C_EXPORT)
	{
		parse_expansion(input, output);
		return (CONTINUE);
	}
	else if (c == C_QUOTE)
		return (BREAK);
	return (DO_NOTHING);
}

static int	backsl_export(t_vector *input, t_vector *output, size_t *index)
{
	size_t i;

	i = 0;
	vct_pop(input);
	safe_vct_add(output, vct_getfirstchar(input));
	vct_pop(input);
	*index = vct_clen(input, C_EXP);
	if (*index == 0 && vct_getfirstchar(input) == C_EXP)
	{
		safe_vct_add(output, C_EXP);
		vct_pop(input);
		return (SUCCESS);
	}
	while (i < *index)
	{
		safe_vct_add(output, vct_getfirstchar(input));
		vct_pop(input);
		i++;
	}
	*index = 2;
	return (FAILURE);
}

int			parse_double_quote(t_vector *input, t_vector *output)
{
	char	c;
	char	next_c;
	size_t	index;
	int		ret;

	vct_pop(input);
	index = 0;
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		next_c = vct_getcharat(input, 1);
		if (c == C_BACKSLASH && next_c == C_EXP)
		{
			if (backsl_export(input, output, &index) == SUCCESS)
				return (SUCCESS);
			break ;
		}
		ret = process_parse_double_quote(c, next_c, input, output);
		if (ret == SUCCESS || ret == FAILURE)
			return (ret);
		if (ret == BREAK)
			break ;
		pop_output_input(ret, c, input, output);
	}
	return (process_pop(index, input, output));
}

int			process_pop(size_t index, t_vector *input, t_vector *output)
{
	if (vct_getfirstchar(input) == C_EXPORT && index == 2)
		parse_expansion(input, output);
	handle_pop(index, output);
	vct_pop(input);
	return (SUCCESS);
}
