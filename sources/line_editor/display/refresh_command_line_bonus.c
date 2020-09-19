#include "line_editor_bonus.h"

static void	move_cursor_at_refresh_startingpoint(t_le *le)
{
	int		head_of_block;

	if (le->vct_index == 0)
		return ;
	if (le->vct_index == (int)vct_getlen(le->cmd_line)
						&& (le->screen_flag & FULL_REFRESH) == FALSE)
		head_of_block = le->vct_index - 1;
	else
		head_of_block = 0;
	while (le->vct_index > head_of_block)
		move_previous_line_head();
}

static void		move_cursor_at_backup(t_le *le, int index_backup, int vct_len)
{
	if (index_backup != UNSET && index_backup < (vct_len - le->vct_index) / 2)
	{
		while (le->vct_index > index_backup)
			move_previous_line_head();
		while (le->vct_index <= index_backup)
			move_cursor_right();
	}
	else if (index_backup != UNSET)
		while (le->vct_index > index_backup)
			move_cursor_left();
}

void		refresh_command_line(void)
{
	int		index_backup;
	int		vct_len;
	t_le	*le;

	le = get_struct(GET);
	vct_len = vct_getlen(le->cmd_line);
	index_backup = (le->vct_index < vct_len) ? le->vct_index : UNSET;
	move_cursor_at_refresh_startingpoint(le);
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	print_cmd_line();
	move_cursor_at_index(vct_len);
	move_cursor_at_backup(le, index_backup, vct_len);
	if (le->screen_flag & FULL_REFRESH)
		le->screen_flag ^= FULL_REFRESH;
}
