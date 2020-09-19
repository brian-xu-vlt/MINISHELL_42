#include "line_editor_bonus.h"

void	insert_char_in_vct(char c)
{
	t_le	*le;

	le = get_struct(GET);
	vct_addcharat(le->cmd_line, le->vct_index, c);
}

void	handle_print_char(char key)
{
	if (get_struct(GET)->select_min != -1)
		delete_selection(0);
	insert_char_in_vct(key);
	move_cursor_right();
	refresh_command_line();
}
