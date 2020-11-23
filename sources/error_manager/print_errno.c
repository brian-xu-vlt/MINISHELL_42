#include "minishell_bonus.h"

static void	put_error(const char *err_str, int colon_flag)
{
	ft_putstr_fd((char *)err_str, STDERR_FILENO);
	if (colon_flag != FALSE)
		ft_putstr_fd(": ", STDERR_FILENO);
}

void		print_invalid_option(const char *function_name,
									const char *error_source, const char *usage)
{
	static const char	*error_str = "invalid option";
	t_vector			*tmp_err_src;

	tmp_err_src = vct_new();
	if (tmp_err_src == NULL)
		exit_routine_le(ERR_MALLOC);
	if (error_source != NULL && ft_strlen(error_source) >= 2)
	{
		safe_vct_add(tmp_err_src, (char)error_source[0]);
		safe_vct_add(tmp_err_src, (char)error_source[1]);
	}
	else
		safe_vct_addstr(tmp_err_src, (char *)error_source);
	print_set_errno(EINVAL, error_str, function_name, vct_getstr(tmp_err_src));
	vct_del(&tmp_err_src);
	if (usage != NULL)
		ft_putstr_fd((char *)usage, STDERR_FILENO);
}

void		print_invalid_identifier(const char *function_name,
													const char *error_source)
{
	static const char	*error_str = "not a valid identifier";
	t_vector			*tmp_err_src;

	tmp_err_src = vct_new();
	if (tmp_err_src == NULL)
		exit_routine_le(ERR_MALLOC);
	safe_vct_add(tmp_err_src, '`');
	safe_vct_addstr(tmp_err_src, (char *)error_source);
	safe_vct_add(tmp_err_src, '\'');
	print_set_errno(EINVAL, error_str, function_name, vct_getstr(tmp_err_src));
	vct_del(&tmp_err_src);
}

void		print_set_errno(int errno_value, const char *err_str,
						const char *function_name, const char *error_source)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	errno = errno_value;
	put_error("Minishell", TRUE);
	if (function_name != NULL)
		put_error(function_name, TRUE);
	if (error_source != NULL)
		put_error(error_source, TRUE);
	if (err_str != NULL)
		put_error(err_str, FALSE);
	else if (errno_value != 0)
		put_error(strerror(errno), FALSE);
	ft_printf("\n");
}
