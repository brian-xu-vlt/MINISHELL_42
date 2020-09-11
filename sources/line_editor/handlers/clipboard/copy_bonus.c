#include "line_editor_bonus.h"

void	copy_selection(t_vector *command_line)
{
	t_le	*le;
	int		copy_start;
	int		copy_end;
	int		i;
	
	le = get_env(GET);
	vct_clear(le->clipboard);
	if (le->vct_index > (int)vct_getlen(command_line))
		return ;
	copy_start = (le->select_min == -1) ? le->vct_index : le->select_min;
	copy_end = (le->select_max == -1) ? le->vct_index : le->select_max;
	i = copy_start;
	while (i <= copy_end)
	{
		vct_add(le->clipboard, vct_getcharat(command_line, i));
		i++;
	}
}

