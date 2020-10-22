#include "minishell_bonus.h"

void	handle_simple(char *str, size_t i, size_t end_simple)
{
	t_vector	*vct_simple;
	
	vct_simple = vct_new();
	vct_addstr(vct_simple, str + i);
	ft_printf("STR_SIMPLE BEGIN = %s\n", vct_getstr(vct_simple));//DEBUG
	vct_cutfrom(vct_simple, vct_getlen(vct_simple) - end_simple);
	ft_printf("VCT_SIMPLE END = %s\n", vct_getstr(vct_simple));//DEBUG
	vct_del(&vct_simple);
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
			ft_printf("END_SIMPLE = %d\n", end_simple);//DEBUG
			return (end_simple);
		}
		end_simple++;
	}
	return (0);
}
