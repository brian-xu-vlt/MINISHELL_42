#include "line_editor_bonus.h"

static void	set_selection(void)
{
	int		vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_len = (int)vct_getlen(le->cmd_line);
	vct_len = (int)vct_getlen(le->cmd_line);
	le->select_min = (le->vct_index < le->vct_index_backup) ?
										le->vct_index : le->vct_index_backup;
	le->select_max = (le->vct_index < le->vct_index_backup) ?
										le->vct_index_backup : le->vct_index;
}

void	update_selection(long buff)
{
	int		vct_len;
	t_le	*le;
(void)buff;
	le = get_env(GET);
	vct_len = (int)vct_getlen(le->cmd_line);
	if (le->vct_index_backup == le->vct_index)
		return;
	if (le->select_min == UNSET)
		set_selection();
	else if (le->vct_index < le->select_min && le->vct_index < le->select_max)
		le->select_min = le->vct_index;
	else if (le->vct_index > le->select_min && le->vct_index > le->select_max)
		le->select_max = le->vct_index;
	else if (buff == K_LEFT)
		le->select_max = le->vct_index;
	else if (buff == K_RIGHT) 
		le->select_min = le->vct_index;
}

void	init_selection()
{
	t_le *le;

	le = get_env(GET);
	le->select_min = UNSET;
	le->select_max = UNSET;
}

void	unselect_all(void)
{
	t_le *le;

	le = get_env(GET);
	if (le->select_min != UNSET)
	{
		init_selection();
		refresh();
	}
}
