#include "line_editor_bonus.h"

void	exit_routine_le(char *err_code)
{
	t_le	*le;

	le = get_env(GET);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(get_env(GET)->termios_backup));
	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	if (err_code != NULL)
	{
		ft_putstr_fd(err_code, STDOUT_FILENO);
		exit(FAILURE);
	}
	exit(0);
}
