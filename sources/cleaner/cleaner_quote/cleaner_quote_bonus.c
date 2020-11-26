#include "minishell_bonus.h"

void		parse_expansion(t_vector *input, t_vector *output)
{
	t_vector	*expansion;
	char		*expansion_value;
	char		c;

	expansion = vct_new();
	vct_pop(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (is_exp_sep(c) && c != QUESTION_MARK)
			break ;
		vct_add(expansion, c);
		vct_pop(input);
	}
	if (vct_getlen(expansion) == 0)
		vct_add(output, C_EXPORT);
	else
	{
		expansion_value = exp_value(vct_getstr(expansion));
		vct_addstr(output, expansion_value);
	}
	vct_del(&expansion);
}

void		parse_simple_quote(t_vector *input, t_vector *output)
{
	char c;

	vct_pop(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (c == C_SIMPLE_QUOTE)
			break ;
		vct_add(output, c);
		vct_pop(input);
	}
	vct_pop(input);
}

int			parse_double_quote(t_vector *input, t_vector *output)
{
	char c;
	char next_c;
	size_t	index;
	size_t	i;

	vct_pop(input);
	i = 0;
	index = 0;
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		next_c = vct_getcharat(input, 1);
		if (c == C_BACKSLASH && next_c == C_EXP)
		{
			vct_pop(input);
			vct_add(output, vct_getfirstchar(input));
			vct_pop(input);
			index = vct_clen(input, C_EXP);
			if (index == 0 && vct_getfirstchar(input) == C_EXP)
			{
				vct_add(output, C_EXP);
				vct_pop(input);
				return (SUCCESS);
			}
			while (i < index)
			{
				vct_add(output, vct_getfirstchar(input));
				vct_pop(input);
				i++;
			}
			index = 2;
			break ;
		}
		if (is_backslash(c, next_c, input) == FAILURE)
			return (FAILURE);
		else if (c == C_EXPORT)
		{
			parse_expansion(input, output);
			continue;
		}
		else if (c == C_QUOTE)
			break ;
		vct_add(output, c);
		vct_pop(input);
	}
	if (vct_getfirstchar(input) == C_EXPORT && index == 2)
		parse_expansion(input, output);
	if (index != 0)
	{
		index = vct_clen(output, C_QUOTE);
		while (index < vct_getlen(output))
		{
			if (vct_getcharat(output, index) != C_QUOTE)
				break ;
			if (vct_getcharat(output, index) == C_QUOTE)
				vct_popcharat(output, index);
		}
	}
	vct_pop(input);
	return (SUCCESS);
}

static int	handle_char(char c, t_vector *input, t_vector *output)
{
	int flag;

	flag = 0;
	if (c == C_BACKSLASH)
	{
		if (handle_backslash_nothing(input, output, c) == FAILURE)
			return (FAILURE);
	}
	else if (c == C_SIMPLE_QUOTE)
	{
		flag = flag | F_SQUOTE;
		parse_simple_quote(input, output);
	}
	else if (c == C_QUOTE)
	{
		if (parse_double_quote(input, output) == FAILURE)
			return (FAILURE);
		flag = flag | F_DQUOTE;
	}
	else if (c == C_EXPORT)
	{
		parse_expansion(input, output);
		if (vct_getfirstchar(output) == C_EXP && vct_getlen(input) != 0
				&& vct_getfirstchar(input) != C_BACKSLASH)
			vct_pop(output);
		flag = flag | F_EXP;
	}
	else
	{
		vct_add(output, c);
		vct_pop(input);
	}
	return (flag);
}

int			process_clean_quote(t_vector *input, t_vector *output)
{
	char c;
	int	flag;

	flag = 0;
	//ft_printf("\n\nINPUT = %s\n", vct_getstr(input));//DEBUG
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		flag = handle_char(c, input, output);
		if (flag == FAILURE)
			return (FAILURE);
	}
//	ft_printf("OUTPUT = %s\n", vct_getstr(output));//DEBUG
//	ft_printf("flag = %d\n", flag);//DEBUG
	if (flag == 8 && vct_getlen(output) == 0)
		return (2);
	if ((flag & F_SQUOTE || flag & F_DQUOTE) && vct_getlen(output) == 0)
	{
		vct_clear(output);
		vct_add(output, '\0');
	}
//	if (output == NULL)
//		ft_printf("OUPUT NULL\n");//DEBUYG
	return (SUCCESS);
}
