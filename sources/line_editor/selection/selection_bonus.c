#include "line_editor_bonus.h"

void	update_select(t_vector *command_line, long buff)
{
	int		vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	if (le->select_min == -1)
	{
		le->select_min = vct_index - ((buff == K_RIGHT) ? 1 : 0);
		le->select_max = vct_index + ((buff == K_LEFT) ? 1 : 0);
	}
	else if (vct_index == 0)
	{
		le->select_min = vct_index;
		return ;
	}
	else if (vct_index >= (int)vct_getlen(command_line))
	{
		le->select_max = (int)vct_getlen(command_line);
		return ;
	}
	else if (vct_index < le->select_min && vct_index < le->select_max)
		le->select_min = vct_index;
	else if (vct_index > le->select_min && vct_index > le->select_max)
		le->select_max = vct_index;
	else if (buff == K_LEFT && vct_index >= le->select_min && vct_index < le->select_max)
		le->select_max = vct_index;
	else if (buff == K_RIGHT && vct_index > le->select_min && vct_index <= le->select_max)
		le->select_min = vct_index;
}

void	init_selection()
{
	t_le *le;

	le = get_env(GET);
	le->select_min = -1;
	le->select_max = -1;
}

void		unselect_all(t_vector *command_line)
{
	init_selection();
	refresh_command_line(command_line);
}
