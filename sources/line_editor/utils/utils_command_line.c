#include "line_editor_bonus.h"

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
				tputs(le->termcap[SELECT], 1, ms_putchar);
			ms_putchar(vct_getcharat(command_line, i));
			tputs(le->termcap[UNSELECT], 1, ms_putchar);
			i++;
		}
	}
}

void		refresh_command_line(t_vector *command_line)
{
	int		vct_index_backup;
	t_le	*le;

//	return ;
	le = get_env(GET);
	tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
	vct_index_backup = convert_cur_pos_vctindex(le->cx, le->cy);
	move_cursor_at_startingpoint();
	print_command_line(command_line);
	update_cursor_pos_with_new_index(vct_getlen(command_line));
	move_cursor_at_index(command_line, vct_index_backup);	
	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
}


