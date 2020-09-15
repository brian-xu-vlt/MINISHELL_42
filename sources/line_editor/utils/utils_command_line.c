#include "line_editor_bonus.h"

void            move_previous_line_head(void)
{
	t_le    *le;
	int		offset;

	le = get_env(GET);

	if (le->cy > 0)
	{
		tputs(le->termcap[ONE_ROW_UP], 1, ms_putchar);
		le->cy--;
	}
	offset = (le->cy == 0) ? le->prompt_len : 0;
	tputs(tparm(le->termcap[MOVE_AT_COL_X], offset), 1, ms_putchar);
	le->cx = offset;
	if (le->cy == 0)
		le->vct_index = 0;
	else
		le->vct_index = (le->scols * (le->cy - 1)) + le->scols - le->prompt_len;
}

void		put_carriage_return(void)
{
	t_le	*le;

	le = get_env(GET);
	tputs(le->termcap[ONE_ROW_DOWN], 1, ms_putchar);
	tputs(tparm(le->termcap[MOVE_AT_COL_X], 0), 2, ms_putchar);
}

void		write_with_selection(t_vector *command_line, int index_from)
{
	int		vct_len;
	char	*v_str;
	int		fd;
	t_le	*le;

	le = get_env(GET);
	v_str = vct_getstr(command_line);
	vct_len = vct_getlen(command_line);
	fd = STDERR_FILENO;
	if (le->select_min < index_from)
	{
		tputs(le->termcap[SELECT], 1, ms_putchar);
		write(fd, v_str + index_from, le->select_max - index_from + 1);
		tputs(le->termcap[UNSELECT], 1, ms_putchar);
		write(fd, v_str + le->select_max + 1, vct_len - le->select_max);
	}
	else
	{
		write(fd, v_str + index_from, le->select_min - index_from);
		tputs(le->termcap[SELECT], 1, ms_putchar);
		write(fd, v_str + le->select_min, le->select_max - le->select_min + 1);
		tputs(le->termcap[UNSELECT], 1, ms_putchar);
		write(fd, v_str + le->select_max + 1, vct_len - le->select_max);
	}	
}

void		print(t_vector *command_line)
{
	int		index_from;
	int		index_delta;
	int		offset;
	t_le	*le;

	le = get_env(GET);
	index_from = le->vct_index;
	index_delta = vct_getlen(command_line) - index_from;
	if (le->select_min == UNSET)
		write(STDERR_FILENO, vct_getstr(command_line) + index_from, index_delta);
	else
		write_with_selection(command_line, index_from);
	offset = (le->cy == 0) ? le->prompt_len : 0;
	if ((index_delta + offset) % le->scols == 0) 
		put_carriage_return();
}

void		move_head_of_refreshed_block(t_vector *command_line)
{
	int		head_of_block;
	t_le	*le;

	le = get_env(GET);
	if (le->select_min != UNSET)
		head_of_block = le->select_min;
	else if (le->vct_index == (int)vct_getlen(command_line))
		head_of_block = le->vct_index - 1;
	else
		head_of_block = 0;
	while (le->vct_index > head_of_block)
		move_previous_line_head();
/*	if (le->overflowing_flag == TRUE)
		le->cy = 
*/
}

void		refresh(t_vector *command_line)
{
	int		index_backup;
	int		vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = vct_getlen(command_line);
	index_backup = (le->vct_index < vct_len) ? le->vct_index : UNSET;
	if (index_backup != UNSET)
		debug_print_flag(ft_itoa(index_backup));
	move_head_of_refreshed_block(command_line);
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	print(command_line);
	move_cursor_at_index(vct_len);
	if (index_backup != UNSET && index_backup < (vct_len - le->vct_index) / 2)
	{
		while (le->vct_index > index_backup)
			move_previous_line_head();
		while (le->vct_index <= index_backup)
			move_cursor_right(command_line);
	}
	else if (index_backup != UNSET)
		while (le->vct_index > index_backup)
			move_cursor_left();
}
