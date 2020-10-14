#include "minishell_bonus.h"

void	print_set_errno(int err_value, char *function_name, char *error_source)
{
	ft_printf("minishell: %s: ", function_name);
	if (error_source != NULL)
		ft_printf("%s: ", error_source);
	if (err_value != 0)
	{
		errno = err_value;
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_printf("\n");
}
