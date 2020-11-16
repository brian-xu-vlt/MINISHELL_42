#include "minishell_bonus.h"

static void	put_error(const char *err_str, int colon_flag)
{
	ft_putstr_fd((char *)err_str, STDERR_FILENO);
	if (colon_flag != FALSE)
		ft_putstr_fd(": ", STDERR_FILENO);
}

void		print_set_errno(int errno_value, const char *err_str,
						const char *function_name, const char *error_source)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	put_error("Minishell", TRUE);
	if (function_name != NULL)
		put_error(function_name, TRUE);
	if (error_source != NULL)
		put_error(error_source, TRUE);
	if (err_str != NULL)
		put_error(err_str, FALSE);
	else if (errno_value != 0)
	{
		errno = errno_value;
		put_error(strerror(errno), FALSE);
	}
	ft_printf("\n");
}
