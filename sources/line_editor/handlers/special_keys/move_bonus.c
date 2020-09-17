#include "line_editor_bonus.h"

void	move_end_of_line(void)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)
		ret = move_cursor_right();
}

void	move_start_of_line(void)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)
		ret = move_cursor_left();
}

void	move_one_word_right(void)
{
	size_t	vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = vct_getlen(le->cmd_line);
	while (le->vct_index < (int)vct_len && vct_getcharat(le->cmd_line, le->vct_index) == ' ')
		move_cursor_right();
	while (le->vct_index < (int)vct_len && vct_getcharat(le->cmd_line, le->vct_index) != ' ')
		move_cursor_right();
}

void	move_one_word_left(void)
{
	t_le	*le;

	le = get_env(GET);
	while (le->vct_index > 0 && vct_getcharat(le->cmd_line, le->vct_index - 1) == ' ')
		move_cursor_left();
	while (le->vct_index > 0 && vct_getcharat(le->cmd_line, le->vct_index - 1) != ' ')
		move_cursor_left();
}


