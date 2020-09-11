#include "line_editor_bonus.h"

int		move_cursor_left(void)
{
	size_t		vct_index;
	char		*buff;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	if (vct_index <= 0)
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
	return (SUCCESS);
}

int		move_cursor_right(t_vector *command_line)
{
	size_t		vct_index;
	char		*buff;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	if (vct_index >= vct_getlen(command_line))
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
	return (SUCCESS);
}

size_t	convert_cur_pos_vctindex(int cx, int cy)
{
	t_le	*le;

	le = get_env(GET);
	return ((cy * le->scols) + cx - le->prompt_len);
}

void	update_cursor_pos_with_new_index(int vct_index)
{
	t_le	*le;

	le = get_env(GET);
	le->cy = (vct_index + le->prompt_len - 1) / le->scols;
	le->cx = vct_index + le->prompt_len -  1 - (le->cy * le->scols);
}

void		move_cursor_at_startingpoint(void)
{
	char	*buff;
	t_le	*le;

	le = get_env(GET);
	buff = tparm(le->termcap[MOVE_AT_COL_X], 0);
    tputs(buff, 1, ms_putchar);
	if (le->cy > 0)
	{
		buff = tparm(le->termcap[MOVE_X_ROWS_UP], le->cy);
		tputs(buff, le->cy, ms_putchar); 
	}
	init_prompt();
}

void		move_cursor_at_index(t_vector *command_line, int target_index)
{
	int		i;

	move_cursor_at_startingpoint();
	i = 0;
	while (i < target_index)
	{
		move_cursor_right(command_line);
		i++;
	}
}
