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

