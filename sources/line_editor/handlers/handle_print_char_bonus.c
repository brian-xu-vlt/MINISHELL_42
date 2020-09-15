#include "line_editor_bonus.h"


int		move_cursor_right_virtualy(t_vector *command_line)
{
	t_le	*le;

	le = get_env(GET);
	if (le->vct_index >= (int)vct_getlen(command_line))
		return (FAILURE);
	if (le->cx >= le->scols - 1)
	{
		le->cx = 0;
		le->cy++;
	}
	else
		le->cx++;
	le->vct_index++;
	return (SUCCESS);
}


void            move_previous_line_startingpoint(void)
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

char		*vct_getstrat(t_vector *vct, size_t index)
{
	if (vct == NULL || vct->str == NULL || index > vct_getlen(vct))
		return (NULL);
	return (vct->str + index);
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
	int		index_to;
	int		index_delta;
	char	*vct_str;
	t_le	*le;

	le = get_env(GET);
	index_from = le->vct_index;
	index_to = (int)vct_getlen(command_line);
	index_delta = index_to - index_from;

	vct_str = vct_getstrat(command_line, index_from);
	if (vct_str == NULL)
		exit_routine_le(ERR_VCT);
	write(STDERR_FILENO, vct_getstrat(command_line, index_from), index_delta);

	int offset = (le->cy == 0) ? le->prompt_len : 0;
	le->cy += (index_delta + offset) / le->scols;
	le->cx = (index_delta + offset) % le->scols;
	le->vct_index = index_to;
	if ((index_delta + offset + 1) % le->scols == 1)
		put_carriage_return();
}

void		refresh(t_vector *command_line)
{
	t_le	*le;

	le = get_env(GET);
	move_previous_line_startingpoint();
	print(command_line);
}


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

	move_cursor_right(command_line);
	refresh(command_line);
}






/*
	int		i;
	if (le->select_min == -1)
	else
	{
		i = index_from;
		while (i <= index_to)
		{
			if (i >= le->select_min && i <= le->select_max)
			tputs(le->termcap[SELECT], 1, ms_putchar);
			ms_putchar(vct_getcharat(command_line, i));
			if (i >= le->select_min && i <= le->select_max)
				tputs(le->termcap[UNSELECT], 1, ms_putchar);
			i++;
		}
	}
*/





//***********************************************************//
/*
	le->cy = (index_delta + le->prompt_len) / le->scols;
	le->cx = (index_delta + le->prompt_len) % le->scols;
	le->vct_index = index_to;
*/
//***********************************************************//

