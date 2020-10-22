#include "minishell_bonus.h"

char	*handle_simple(char *str, size_t i, size_t end_simple)
{
	t_vector	*vct_simple;
	char		*good_str;

	vct_simple = vct_new();
	vct_addstr(vct_simple, str + i);
	vct_cutfrom(vct_simple, vct_getlen(vct_simple) - end_simple);
	vct_pop(vct_simple);
	vct_cut(vct_simple);
	good_str = ft_strdup(vct_getstr(vct_simple));
	vct_del(&vct_simple);
	return (good_str);
}

size_t	end_simple(char *str, size_t i)
{
	size_t		end_simple;
	char		*new_str;

	new_str = str + i;
	end_simple = 1;
	while (new_str[end_simple] != '\0')
	{
		if (new_str[end_simple] == C_SIMPLE_QUOTE)
		{
			end_simple++;
			return (end_simple);
		}
		end_simple++;
	}
	return (0);
}
