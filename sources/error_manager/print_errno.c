#include "minishell_bonus.h"

void	print_errno(char *function_name, char *error_source)
{
	ft_printf("%s: ", function_name);
	if (error_source != NULL)
		ft_printf("%s: ", error_source);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_printf("\n");
}
