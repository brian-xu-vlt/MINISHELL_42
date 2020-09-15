#include "line_editor_bonus.h"

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

//* do refresh + move right, but refresh only up to len -1 !!!!!!

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
