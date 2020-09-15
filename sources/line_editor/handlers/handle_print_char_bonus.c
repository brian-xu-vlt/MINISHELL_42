#include "line_editor_bonus.h"

void	insert_char_in_vct(t_vector *command_line, char c)
{
	t_le	*le;

	le = get_env(GET);
	vct_addcharat(command_line, le->vct_index, c);
}

void	handle_print_char(char buff, t_vector *command_line)
{
	t_le	*le;

	le = get_env(GET);
	if (le->select_min != -1)
		delete_selection(command_line, 0);
	insert_char_in_vct(command_line, buff);	
	refresh(command_line);
}
