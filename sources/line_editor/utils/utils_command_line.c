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
	tputs(tparm(le->termcap[MOVE_AT_COL_X], 0), 2, ms_putchar);
	tputs(le->termcap[ONE_ROW_DOWN], 1, ms_putchar);
}


void		print(t_vector *command_line)
{
	int		index_from;
	int		index_delta;
	int		offset;
	char	*vct_str;
	t_le	*le;

	le = get_env(GET);
	index_from = le->vct_index;
	index_delta = vct_getlen(command_line) - index_from;

	vct_str = vct_getstrat(command_line, index_from);
	if (vct_str == NULL)
		exit_routine_le(ERR_VCT);
	write(STDERR_FILENO, vct_getstrat(command_line, index_from), index_delta);

	offset = (le->cy == 0) ? le->prompt_len : 0;
	if ((index_delta + offset) % le->scols == 0) 
		put_carriage_return();
	move_cursor_at_index(vct_getlen(command_line));
}

void		refresh(t_vector *command_line)
{
	int		index_backup;
	t_le	*le;

	le = get_env(GET);
	index_backup = le->vct_index;
	move_previous_line_head();
	print(command_line);
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
	if (le->select_min == -1)
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
