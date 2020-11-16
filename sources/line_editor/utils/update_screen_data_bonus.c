#include "line_editor_bonus.h"

void	update_window_size(void)
{
	int				ret;
	struct winsize	w_size;
	t_le			*le;

	le = get_struct(GET);
	if (DEBUG_MODE == TRUE)
	{
		le->srows = 1042;
		le->scols = 1042;
	}
	else
	{
		ret = ioctl(STDIN_FILENO, TIOCGWINSZ, &w_size);
		if (ret == FAILURE || w_size.ws_col == 0)
			exit_routine_le(ERR_NO_MESSAGE);
		if (le->srows != 0 && le->scols != 0
				&& (le->srows > w_size.ws_row || le->scols > w_size.ws_col))
			le->screen_flag |= RESIZE_REFRESH;
		le->srows = w_size.ws_row;
		le->scols = w_size.ws_col;
		if (le->screen_flag != 0)
			refresh_command_line();
	}
}
