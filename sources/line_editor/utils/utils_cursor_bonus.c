#include "line_editor_bonus.h"

int		move_cursor_left(void)
{
	size_t		vct_index;
	char		*buff;

	vct_index = convert_cur_pos_vctindex(g_le.cx, g_le.cy);
	if (vct_index <= 0)
		return (FAILURE);
	if (g_le.cx == 0 && g_le.cy > 0)
	{
		tputs(tgetstr("up", NULL), 2, ms_putchar); // cursor 1 row down
		buff = tparm(tgetstr("ch", NULL), g_le.scols); //param termcap for col argument
		tputs(buff, 2, ms_putchar); //
		g_le.cx = g_le.scols - 1;
		g_le.cy--;
	}
	else
	{
		tputs(tgetstr("le", NULL), 1, ms_putchar); // cursor 1 col left 
		g_le.cx--;
	}
	return (SUCCESS);
}

//void	move_cursor_to_index(t_vector *command_line)

int		move_cursor_right(t_vector *command_line)
{
	size_t		vct_index;
	char		*buff;

	vct_index = convert_cur_pos_vctindex(g_le.cx, g_le.cy);
	if (vct_index >= vct_getlen(command_line))
		return (FAILURE);
	if (g_le.cx >= g_le.scols - 1)
	{
		buff = tparm(tgetstr("ch", NULL), 0); //set param termcap for col argument at 0
		tputs(buff, 2, ms_putchar); // cursor @ col 0 of same line
		tputs(tgetstr("do", NULL), 2, ms_putchar); // cursor 1 row down
		g_le.cx = 0;
		g_le.cy++;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 1, ms_putchar); // cursor 1 col right 
		g_le.cx++;
	}
	return (SUCCESS);
}

size_t	convert_cur_pos_vctindex(int cx, int cy)
{
	return ((cy * g_le.scols) + cx - g_le.prompt_len);
}

void	convert_vctindex_cur_pos(int vct_index)
{
	g_le.cy = (vct_index + g_le.prompt_len - 1) / g_le.scols;
	g_le.cx = vct_index + g_le.prompt_len -  1 - (g_le.cy * g_le.scols);
}
