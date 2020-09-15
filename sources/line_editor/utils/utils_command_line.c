#include "line_editor_bonus.h"

char		*vct_getstrat(t_vector *vct, size_t index)
{
	if (vct == NULL || vct->str == NULL || index > vct_getlen(vct))
		return (NULL);
	return (vct->str + index);
}

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

void		move_terminal_cursor_at_index(int index_to)
{
	int		index_delta;
	int		offset;
	int		cx_backup;
	int		cy_backup;
	t_le	*le;

	le = get_env(GET);
	cx_backup = le->cx;
	cy_backup = le->cy;
	offset = (le->cy == 0) ? le->prompt_len : 0;
	index_delta = index_to - le->vct_index;
	
	if (index_delta <= 0)
		return	;
	le->cy += (index_delta + offset) / le->scols;
	le->cx = (index_delta + offset) % le->scols;
	le->vct_index = index_to;
	if (le->cx != cx_backup)
		tputs(tparm(le->termcap[MOVE_AT_COL_X], le->cx), 1, ms_putchar);
	if (le->cy - cy_backup > 0)
		tputs(tparm(le->termcap[MOVE_X_ROWS_DOWN], cy_backup - le->cy), 1, ms_putchar);

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

void		refresh(t_vector *command_line)
{
	int		index_backup;
	int		vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = vct_getlen(command_line);
	index_backup = (le->vct_index < vct_len) ? le->vct_index : UNSET;
	while (le->vct_index > 0)
		move_previous_line_head();
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










/*
static void    update_cursor_infos(int new_index)
{
	t_le    *le;

	le = get_env(GET);
	le->vct_index = new_index;
	le->cy = (new_index + le->prompt_len - 1) / le->scols;
	le->cx = new_index + le->prompt_len -  1 - (le->cy * le->scols);
}

static void		print_command_line(t_vector *command_line, int vct_offset)
{
	int		i;
	int		vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = vct_getlen(command_line);
	//tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	if (le->select_min == UNSET)
		ft_putstr_fd(vct_getstr(command_line) + vct_offset, STDOUT_FILENO);
	else
	{
		i = vct_offset;
		while (i <= vct_len)
		{
			if (i >= le->select_min && i <= le->select_max)
			tputs(le->termcap[SELECT], 1, ms_putchar);
			ms_putchar(vct_getcharat(command_line, i));
			if (i >= le->select_min && i <= le->select_max)
				tputs(le->termcap[UNSELECT], 1, ms_putchar);
			i++;
		}
	}
	update_cursor_infos(vct_len);
	if (vct_offset > 0)
		move_cursor_left();
}


void		refresh_command_line(t_vector *command_line)
{
	int		vct_offset;
	int		vct_index_backup;
	t_le	*le;

	refresh(command_line);
	return ;

	le = get_env(GET);
	vct_index_backup = le->vct_index;
	vct_offset = move_cursor_at_startingpoint();
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	if (le->vct_history == NULL)
		print_command_line(command_line, vct_offset);
	else
		print_command_line(le->vct_history, vct_offset);
	move_cursor_at_index(command_line, vct_index_backup);
}
*/
