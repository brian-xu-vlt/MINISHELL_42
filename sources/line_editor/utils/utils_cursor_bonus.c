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
		tputs(tgetstr("up", NULL), 2, ms_putchar); // cursor 1 row down
		buff = tparm(tgetstr("ch", NULL), le->scols); //param termcap for col argument
		tputs(buff, 2, ms_putchar); //
		le->cx = le->scols - 1;
		le->cy--;
	}
	else
	{
		tputs(tgetstr("le", NULL), 1, ms_putchar); // cursor 1 col left 
		le->cx--;
	}
	return (SUCCESS);
}

//void	move_cursor_to_index(t_vector *command_line)

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
		buff = tparm(tgetstr("ch", NULL), 0); //set param termcap for col argument at 0
		tputs(buff, 2, ms_putchar); // cursor @ col 0 of same line
		tputs(tgetstr("do", NULL), 2, ms_putchar); // cursor 1 row down
		le->cx = 0;
		le->cy++;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 1, ms_putchar); // cursor 1 col right 
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
	buff = tparm(tgetstr("ch", NULL), 0); //set cursor after prompt
	tputs(buff, 1, ms_putchar);
	if (le->cy > 0)
	{
		buff = tparm(tgetstr("UP", NULL), le->cy); //set cursor at line 0 of line editor
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
