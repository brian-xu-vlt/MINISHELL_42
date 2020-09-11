#include "line_editor_bonus.h"

void	delete_backward(t_vector *command_line)
{
	t_le	*le;
	size_t	vct_index;

	le = get_env(GET);
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);	
	if (vct_index > 0)
	{
		move_cursor_left();
		tputs(le->termcap[DELETE_ONE_CHAR], 1, ms_putchar);
		vct_popcharat(command_line, vct_index - 1);
	}
}

void	delete_foreward(t_vector *command_line)
{
	t_le	*le;
	size_t	vct_index;

	le = get_env(GET);
	tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);	
	tputs(le->termcap[DELETE_ONE_CHAR], 1, ms_putchar);
	vct_popcharat(command_line, vct_index);
}
