#include "line_editor_bonus.h"

static void    update_cy_cx_at_vct_index()
{
	t_le    *le;

	le = get_env(GET);
	le->cy = (le->vct_index + le->prompt_len - 1) / le->scols;
	le->cx = le->vct_index + le->prompt_len -  1 - (le->cy * le->scols);
}

void		print_command_line(t_vector *command_line)
{
	int		i;
	int		vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = vct_getlen(command_line);
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	if (le->select_min == -1)
		vct_print_fd(command_line, STDERR_FILENO);
	else
	{
		i = 0;
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
	le->vct_index = vct_len;
	update_cy_cx_at_vct_index();
}

void		refresh_command_line(t_vector *command_line)
{
	int		vct_index_backup;
	t_le	*le;

	le = get_env(GET);
	vct_index_backup = le->vct_index;
	move_cursor_at_startingpoint();
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	print_command_line(command_line);
	move_cursor_at_index(command_line, vct_index_backup);	
}














//	int		vct_index_at_head_of_line;
/*	vct_index_at_head_of_line = le->vct-index; 
	ft_putstr_fd(vct_getstr(command_line) + vct_index_at_head_of_line, STDERR_FILENO );
*/

