#include "line_editor_bonus.h"

void	update_window_size(void)
{
	int				ret;
	struct winsize	w_size;
	t_le			*le;

	le = get_struct(GET);
	if (DEBUG_LLDB == FALSE)
	{
		ret = ioctl(STDIN_FILENO, TIOCGWINSZ, &w_size);
		if (ret == FAILURE || w_size.ws_col == 0)
			exit_routine_le(ERR_NO_MESSAGE);
		if (le->srows != 0 && le->scols != 0
				&& (le->srows > w_size.ws_row || le->scols > w_size.ws_col)
				&& (w_size.ws_col <= le->vct_index))
			le->screen_flag |= FULL_REFRESH; 
		le->srows = w_size.ws_row;
		le->scols = w_size.ws_col;
	}
	else
	{
		le->srows = 1042;
		le->scols = 42;
	}
}
