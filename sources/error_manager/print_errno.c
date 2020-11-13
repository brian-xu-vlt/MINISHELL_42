#include "minishell_bonus.h"

void	print_set_errno(int errno_value, const char *err_str,
						const char *function_name, const char *error_source)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("Minishell: ");
	if (function_name != NULL)
		ft_printf("%s: ", function_name);
	if (error_source != NULL)
		ft_printf("%s: ", error_source);
	if (err_str != NULL)
		ft_printf("%s ", err_str);
	else if (errno_value != 0)
	{
		errno = errno_value;
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	}
	ft_printf("\n");
}
