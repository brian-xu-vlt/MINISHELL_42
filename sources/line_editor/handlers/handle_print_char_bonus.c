#include "line_editor_bonus.h"

// doesn't handle pasted text longer than one byte ! need to fix !
void	insert_char_in_vct(t_vector *command_line, char c)
{
	t_le	*le;
	le = get_env(GET);
	vct_addcharat(command_line, le->vct_index, c);
}

void	handle_print_char(char buff, t_vector *command_line)
{
	insert_char_in_vct(command_line, buff);	
	move_cursor_right(command_line);
	refresh_command_line(command_line);
}
