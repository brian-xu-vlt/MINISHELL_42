#include "minishell_bonus.h"

static void	debug_print_env(t_vector *input)
{
	char *str;

	str = vct_getstr(input);
	str += ft_strlen("print") + 1;
	print_env(str);
}

static void	debug_store_env(t_vector *input)
{
	char *str;

	str = vct_getstr(input);
	str += ft_strlen("store") + 1;
	store_env(str);
}

int	test(t_vector *input)
{
	ft_printf("\n%s\n", vct_getstr(input));
	if (ft_strncmp(vct_getstr(input), "1", 2) == 0)
		print_env(ALL);	
	if (ft_strncmp(vct_getstr(input), "2", 2) == 0)
		print_env("TERM");
	if (ft_strncmp(vct_getstr(input), "store", 5) == 0)
		debug_store_env(input);	
	if (ft_strncmp(vct_getstr(input), "print", 5) == 0)
		debug_print_env(input);	
	return (SUCCESS);
}

