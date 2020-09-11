#include "line_editor_bonus.h"

// doesn't handle pasted text longer than one byte ! need to fix !
void	insert_char_in_vct(t_vector *command_line, char c)
{
	size_t	vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);	
	vct_addcharat(command_line, vct_index, c);
	update_cursor_pos_with_new_index(vct_index + 1);
}

void	handle_print_char(char buff, t_vector *command_line)
{
	insert_char_in_vct(command_line, buff);	
	move_cursor_right(command_line);
	refresh_command_line(command_line);
}
