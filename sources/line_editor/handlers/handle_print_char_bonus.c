#include "line_editor_bonus.h"

static void		move_cursor_at_startingpoint(void)
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

void		print_command_line(t_vector *command_line)
{
	int		i;
	int		vct_len;
	t_le	*le;

	le = get_env(GET);
	if (le->select_min == -1)
		vct_print_fd(command_line, STDERR_FILENO);
	else
	{
		i = 0;
		vct_len = vct_getlen(command_line);
		while (i <= vct_len)
		{
			if (i >= le->select_min && i <= le->select_max)
				tputs(tgetstr("so", NULL), 1, ms_putchar);
			ms_putchar(vct_getcharat(command_line, i));
			tputs(tgetstr("se", NULL), 1, ms_putchar);
			i++;
		}
	}
}

void		refresh_command_line(t_vector *command_line)
{
	int		current_vct_index;
	int		i;
	t_le	*le;

	le = get_env(GET);
	tputs(tgetstr("vi", NULL), 1, ms_putchar); // cursor invisible
	current_vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
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
	size_t	vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);	
	if (vct_addcharat(command_line, vct_index, buff[0]) != SUCCESS)
		exit_routine_le(ERR_VCT);
	move_cursor_right(command_line);
	refresh_command_line(command_line);
}
