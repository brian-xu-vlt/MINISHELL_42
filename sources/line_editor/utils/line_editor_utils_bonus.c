#include "line_editor_bonus.h"

int		ms_tputs(const char *str, int affcnt, int (*putc_function)(int))
{
	int			ret;

	errno = 0;
	ret = tputs(str, affcnt, putc_function);
	if (ret == FAILURE)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		ft_putchar_fd('\r', STDERR_FILENO);
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine_le(ERR_MS_TPUTS);
	}
	return (ret);
}

int		ms_putchar(int c)
{
	int			ret;

	errno = 0;
	ret = write(STDERR_FILENO, &c, 1);
	if (ret == FAILURE)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		ft_putchar_fd('\r', STDERR_FILENO);
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine_le(ERR_MS_PUTCHAR);
	}
	return (ret);
}

t_le	*get_struct(t_le *mem)
{
	static t_le	*mem_backup = NULL;

	if (mem != NULL)
		mem_backup = mem;
	else if (mem == NULL && mem_backup == NULL)
		exit_routine_le(ERR_MALLOC);
	return (mem_backup);
}
