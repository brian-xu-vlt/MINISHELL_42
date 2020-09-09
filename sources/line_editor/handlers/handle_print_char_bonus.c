#include "line_editor_bonus.h"

static void		move_cursor_at_startingpoint(void)
{
	char		*buff;

	buff = tparm(tgetstr("ch", NULL), 0); //set cursor after prompt
	tputs(buff, 1, ms_putchar);
	if (g_le.cy > 0)
	{
		buff = tparm(tgetstr("UP", NULL), g_le.cy); //set cursor at line 0 of line editor
		tputs(buff, g_le.cy, ms_putchar); 
	}
	init_prompt();
}

void		print_command_line(t_vector *command_line)
{
	int			i;
	int			vct_len;

	if (g_le.select_min == -1)
		vct_print_fd(command_line, STDERR_FILENO);
	else
	{
		i = 0;
		vct_len = vct_getlen(command_line);
		while (i <= vct_len)
		{
			if (i >= g_le.select_min && i <= g_le.select_max)
				tputs(tgetstr("so", NULL), 1, ms_putchar);
			ms_putchar(vct_getcharat(command_line, i));
			tputs(tgetstr("se", NULL), 1, ms_putchar);
			i++;
		}
	}
}

void		refresh_command_line(t_vector *command_line)
{
	int			current_vct_index;
	int			i;

	tputs(tgetstr("vi", NULL), 1, ms_putchar); // cursor invisible
	current_vct_index = convert_cur_pos_vctindex(g_le.cx, g_le.cy);
	move_cursor_at_startingpoint();
	tputs(tgetstr("cd", NULL), 1, ms_putchar); //clear
	print_command_line(command_line);
	convert_vctindex_cur_pos(vct_getlen(command_line));
	move_cursor_at_startingpoint();
	i = 0;
	while (i < current_vct_index)
	{
		move_cursor_right(command_line);
		i++;
	}
	tputs(tgetstr("ve", NULL), 1, ms_putchar); // cursor visible
}


// doesn't handle pasted text longer than one byte !
void		handle_print_char(char *buff, t_vector *command_line)
{
	size_t		vct_index;

	vct_index = convert_cur_pos_vctindex(g_le.cx, g_le.cy);	
	if (vct_addcharat(command_line, vct_index, buff[0]) != SUCCESS)
		exit_routine_le(ERR_VCT);
	move_cursor_right(command_line);
	refresh_command_line(command_line);
}
