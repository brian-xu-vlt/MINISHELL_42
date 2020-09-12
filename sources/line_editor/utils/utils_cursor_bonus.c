#include "line_editor_bonus.h"

int		move_cursor_left(void)
{
	char		*buff;
	t_le	*le;

	le = get_env(GET);
	if (le->vct_index <= 0)
		return (FAILURE);
	if (le->cx == 0 && le->cy > 0)
	{
		tputs(le->termcap[ONE_ROW_UP], 1, ms_putchar);
		buff = tparm(le->termcap[MOVE_AT_COL_X], le->scols);
		tputs(buff, 2, ms_putchar);
		le->cx = le->scols - 1;
		le->cy--;
	}
	else
	{
		tputs(le->termcap[ONE_COL_LEFT], 1, ms_putchar);
		le->cx--;
	}
	le->vct_index--;
	return (SUCCESS);
}

int		move_cursor_right(t_vector *command_line)
{
	char		*buff;
	t_le	*le;

	le = get_env(GET);
//	if (le->cy >= le->srows)
//		exit_routine_le(ERR_SCREEN_SIZE);
	if (le->vct_index >= (int)vct_getlen(command_line))
		return (FAILURE);
	if (le->cx >= le->scols - 1)
	{
		buff = tparm(le->termcap[MOVE_AT_COL_X], 0);
		tputs(buff, 2, ms_putchar);
		tputs(le->termcap[ONE_ROW_DOWN], 1, ms_putchar);
		le->cx = 0;
		le->cy++;
	}
	else
	{
		tputs(le->termcap[ONE_COL_RIGHT], 1, ms_putchar);
		le->cx++;
	}
	le->vct_index++;
	return (SUCCESS);
}

int            move_cursor_at_startingpoint(t_vector *command_line)
{
	int		offset;
	char    *buff;
	t_le    *le;

	le = get_env(GET);
	offset = 0;
	buff = tparm(le->termcap[MOVE_AT_COL_X], 0);
	tputs(buff, 1, ms_putchar);
	if (le->cy >= le->srows)
		offset = (le->cy + 1 - le->srows) * le->scols - le->prompt_len; 
	if (le->cy > 0)
	{
		buff = tparm(le->termcap[MOVE_X_ROWS_UP], (offset == 0) ? le->cy : ((vct_getlen(command_line) - offset) / le->scols) + 1);
		tputs(buff, le->cy, ms_putchar);
	}
	if (offset == 0)
		init_prompt();
	else
	{
		le->cy = le->cy + 1 - le->srows;
		le->cx = 0;
		le->vct_index = offset;
	}
	return (offset);
}

void		move_cursor_at_index(t_vector *command_line, int target_index)
{
	int		i;
	int		offset;
	t_le	*le;

	le = get_env(GET);
	offset = move_cursor_at_startingpoint(command_line);
	i = 0 + offset;
	while (i < target_index)
	{
		move_cursor_right(command_line);
		i++;
	}
}
