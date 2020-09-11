#include "line_editor_bonus.h"

void	copy_selection(t_vector *command_line)
{
	t_le	*le;
	int		copy_start;
	int		copy_end;
	int		vct_index;
	int		i;
	
	le = get_env(GET);
	vct_clear(le->clipboard);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	if (vct_index > (int)vct_getlen(command_line))
		return ;
	copy_start = (le->select_min == -1) ? vct_index : le->select_min;
	copy_end = (le->select_max == -1) ? vct_index : le->select_max;
	i = copy_start;
	while (i <= copy_end)
	{
		vct_add(le->clipboard, vct_getcharat(command_line, i));
		i++;
	}
}

