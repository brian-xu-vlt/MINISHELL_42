#include "minishell_bonus.h"

bool is_wrong_char_export(t_vector *vct)
{
	size_t i;

	while (vct_getlen(vct) > 0)
	{
		i = 0;
		while (i < NB_DEL_EXPORT)
		{
			if (vct_getfirstchar(vct) == DEL_EXPORT[i])
				return (true);
			i++;
		}
		vct_pop(vct);
	}
	return (false);
}

bool	is_quote_false(t_vector	*vct)
{
	t_vector	*pop;

	pop = vct_new();
	while (vct_getlen(vct) > 0)
	{
		vct_cpy(pop, vct);
		if (vct_getfirstchar(vct) == C_SIMPLE_QUOTE)
		{
			vct_pop(pop);
			if (vct_getfirstchar(pop) == C_QUOTE)
			{
				ft_printf("IS_QUOTE_FALSE SIMPLE_QUOTE\n");
				vct_del(&pop);
				return (true);
			}
		}
		if (vct_getfirstchar(vct) == C_QUOTE)
		{
			vct_pop(pop);
			if (vct_getfirstchar(pop) == C_SIMPLE_QUOTE)
			{
				ft_printf("IS_QUOTE_FALSE SIMPLE_QUOTE\n");
				vct_del(&pop);
				return (true);
			}
		}
		vct_clear(pop);
		vct_pop(vct);
	}
	vct_del(&pop);
	return (false);
}