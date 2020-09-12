#include "line_editor_bonus.h"

void	move_end_of_line(t_vector *command_line)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)	
		ret = move_cursor_right(command_line);
}

void	move_start_of_line(void)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)	
		ret = move_cursor_left();
}

void	move_one_word_right(t_vector *command_line)
{
	size_t	vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = vct_getlen(command_line);
	while (le->vct_index < (int)vct_len && vct_getcharat(command_line, le->vct_index) == ' ')
		move_cursor_right(command_line);
	while (le->vct_index < (int)vct_len && vct_getcharat(command_line, le->vct_index) != ' ')
		move_cursor_right(command_line);
}

void	move_one_word_left(t_vector *command_line)
{
	t_le	*le;

	le = get_env(GET);
	while (le->vct_index > 0 && vct_getcharat(command_line, le->vct_index - 1) == ' ')
		move_cursor_left();
	while (le->vct_index > 0 && vct_getcharat(command_line, le->vct_index - 1) != ' ')
		move_cursor_left();
}


