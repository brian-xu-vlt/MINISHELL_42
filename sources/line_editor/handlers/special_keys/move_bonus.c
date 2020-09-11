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
	size_t	vct_index;
	size_t	vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	vct_len = vct_getlen(command_line);
	while (vct_index < vct_len && vct_getcharat(command_line, vct_index) == ' ')
	{
		move_cursor_right(command_line);
		update_selection(command_line, K_RIGHT);
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	while (vct_index < vct_len && vct_getcharat(command_line, vct_index) != ' ')
	{
		move_cursor_right(command_line);
		update_selection(command_line, K_RIGHT);
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	update_selection(command_line, K_RIGHT);
}

void	move_one_word_left(t_vector *command_line)
{
	size_t	vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	while (vct_index > 0 && vct_getcharat(command_line, vct_index - 1) == ' ')
	{
		move_cursor_left();
		update_selection(command_line, K_LEFT);
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	while (vct_index > 0 && vct_getcharat(command_line, vct_index - 1) != ' ')
	{
		move_cursor_left();
		update_selection(command_line, K_LEFT);
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	update_selection(command_line, K_LEFT);
}


