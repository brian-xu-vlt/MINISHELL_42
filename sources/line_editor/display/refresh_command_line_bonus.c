#include "minishell_bonus.h"

static void	refresh_whole_window(t_le *le)
{
	ms_tputs(le->termcap[MOVE_CURSOR_HOME], le->cy, ms_putchar);
	ms_tputs(le->termcap[CLEAR_ALL_AFTER_CURS], le->cy, ms_putchar);
	init_prompt();
	le->screen_flag |= FULL_REFRESH;
}

static void	move_cursor_at_refresh_startingpoint(t_le *le, int head_of_block)
{
	while (le->vct_index > head_of_block)
		move_previous_line_head();
	if (head_of_block == 0)
	{
		ms_tputs(tparm(le->termcap[MOVE_AT_COL_X], 0), 2, ms_putchar);
		// ms_tputs(tparm(le->termcap[MOVE_AT_COL_X], le->prompt_len), 2, ms_putchar);
		ms_tputs(le->termcap[CLEAR_LINE], 1, ms_putchar);
		print_prompt();
	}
}

static void	identify_refresh_startingpoint(t_le *le)
{
	int		head_of_block;

	if (le->screen_flag & RESIZE_REFRESH)
		refresh_whole_window(le);
	if (le->vct_index == 0)
		return ;
	if (le->vct_index == (int)vct_getlen(le->cmd_line)
						&& (le->screen_flag & FULL_REFRESH) == FALSE)
		head_of_block = le->vct_index - 1;
	else
		head_of_block = 0;
	move_cursor_at_refresh_startingpoint(le, head_of_block);
}

static void	move_cursor_at_backup(t_le *le, int index_backup, int vct_len)
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
	if (le != NULL)
	{
		vct_len = vct_getlen(le->cmd_line);
		index_backup = (le->vct_index < vct_len) ? le->vct_index : UNSET;
		identify_refresh_startingpoint(le);
		ms_tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
		print_cmd_line();
		move_cursor_at_index(vct_len);
		if ((le->screen_flag & HISTORY_REFRESH) == FALSE)
			move_cursor_at_backup(le, index_backup, vct_len);
		le->screen_flag = 0;
	}
}
