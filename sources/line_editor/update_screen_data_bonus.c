#include "line_editor_bonus.h"

void	update_window_size(void)
{
	int				ret;
	struct winsize	w_size;

	if (DEBUG_LLDB == FALSE)
	{
		ret = ioctl(STDIN_FILENO, TIOCGWINSZ, &w_size);
		if (ret == FAILURE || w_size.ws_col == 0)
			exit_routine_le("IOCTL failed");
		g_le.srows = w_size.ws_row;	
		g_le.scols = w_size.ws_col;	
	}
	else
	{
		g_le.srows = 42;	
		g_le.scols = 42;
	}
	if (g_le.cy >= g_le.srows)
		exit_routine_le(ERR_SCREEN_SIZE);
}
