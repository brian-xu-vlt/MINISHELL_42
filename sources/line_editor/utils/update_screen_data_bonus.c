#include "minishell_bonus.h"


void	update_window_size(void)
{
	int				ret;
	struct winsize	w_size;
	t_le			*le;

	le = get_struct(GET);
	if (DEBUG_MODE != TRUE && le != NULL)
	{
		ret = ioctl(STDIN_FILENO, TIOCGWINSZ, &w_size);
		if (ret == FAILURE)
			exit_routine(EXIT_NORMAL);
		le->srows = w_size.ws_row;
		le->scols = w_size.ws_col;
	}
}
