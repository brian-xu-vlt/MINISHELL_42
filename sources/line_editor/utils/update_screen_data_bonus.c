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
			exit_routine_le("IOCTL failed");
		le->srows = w_size.ws_row;
		le->scols = w_size.ws_col;
	}
	else
	{
		le->srows = 1042;
		le->scols = 42;
	}
}
