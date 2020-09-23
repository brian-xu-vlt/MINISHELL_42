#include "minishell_bonus.h"

int	test(t_vector *input)
{
	ft_printf("\n%s\n", vct_getstr(input));
	if (ft_strncmp(vct_getstr(input), "1", 2) == 0)
		print_env(ALL);	
	return (SUCCESS);
}

