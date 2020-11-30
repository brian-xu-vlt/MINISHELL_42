#include "minishell_bonus.h"

void	pop_input(t_vector *input, t_vector *output)
{
	char c;

	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (c == C_EXP)
			return ;
		safe_vct_add(output, c);
		vct_pop(input);
	}
}

void	handle_pop(size_t index, t_vector *output)
{
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
}

void	pop_output_input(int ret, char c, t_vector *input, t_vector *output)
{
	if (ret != CONTINUE)
	{
		safe_vct_add(output, c);
		vct_pop(input);
	}
}

void	pop_input_output(char c, t_vector *input, t_vector *output)
{
	safe_vct_add(output, c);
	vct_pop(input);
}
