#include "line_editor_bonus.h"

void	delete_selection(t_vector *command_line, long key)
{
	t_le	*le;
	int		i;

	le = get_env(GET);
	if (le->select_min == -1)
	{
		vct_popcharat(command_line, le->vct_index);
		if (key == K_DEL_BACKWARD)
			move_cursor_left();
	}
	else
	{
		i = le->select_max;
		while(i >= 0 && i >= le->select_min)
			vct_popcharat(command_line, i--);
		unselect_all(command_line);
	}
}
