#include "line_editor_bonus.h"

void	apply_del_backward(t_vector *command_line)
{
	t_le	*le;
	size_t	vct_index;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);	
	if (vct_index > 0)
	{
		move_cursor_left();
		tputs(tgetstr("dc", NULL), 2, ms_putchar); // delete 1 char
		vct_popcharat(command_line, vct_index - 1);
	}
}

void	apply_del_foreward(t_vector *command_line)
{
	t_le	*le;
	size_t	vct_index;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);	
	tputs(tgetstr("dc", NULL), 2, ms_putchar); // delete 1 char
	vct_popcharat(command_line, vct_index);
}

void	apply_end(t_vector *command_line)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)	
		ret = move_cursor_right(command_line);
}

void	apply_home()
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)	
		ret = move_cursor_left();
}

void	apply_ctrl_right(t_vector *command_line)
{
	size_t	vct_index;
	size_t	vct_len;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	vct_len = vct_getlen(command_line);
	while (vct_index < vct_len && vct_getcharat(command_line, vct_index) == ' ')
	{
		move_cursor_right(command_line);
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	while (vct_index < vct_len && vct_getcharat(command_line, vct_index) != ' ')
	{
		move_cursor_right(command_line);
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
}

void	apply_ctrl_left(t_vector *command_line)
{
	size_t	vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	while (vct_index > 0 && vct_getcharat(command_line, vct_index) != ' ')
	{
		move_cursor_left();
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	while (vct_index > 0 && vct_getcharat(command_line, vct_index) == ' ')
	{
		move_cursor_left();
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
	while (vct_index > 0 && vct_getcharat(command_line, vct_index - 1) != ' ')
	{
		move_cursor_left();
		vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	}
}

static long	strip_off_extra_bits(long buff)
{
	return ((buff & 0xff0000000000) >> 24 | (buff & 0xffff)); 
}

void	handle_esc_seq(long buff, t_vector *command_line)
{
	int	shift_flag;
	int	ctrl_flag;
	int	ctrl_shift_flag;

	if ((ctrl_shift_flag = is_ctrl_shift_on(buff)) == TRUE)
		buff = strip_off_extra_bits(buff);
	if ((shift_flag = is_shift_on(buff)) == TRUE)
		buff = strip_off_extra_bits(buff);
	if ((ctrl_flag = is_ctrl_on(buff)) == TRUE)
		buff = strip_off_extra_bits(buff);
	
	if (ctrl_flag == TRUE && buff == K_RIGHT)
		apply_ctrl_right(command_line);
	else if (ctrl_flag == TRUE && buff == K_LEFT)
		apply_ctrl_left(command_line);
	else if (buff == K_LEFT)
		move_cursor_left();
	else if (buff == K_RIGHT)
		move_cursor_right(command_line);
	else if (buff == K_HOME)
		apply_end(command_line);
	else if (buff == K_END)
		apply_home();
	else if (buff == K_DEL_BACKWARD)
		apply_del_backward(command_line);
	else if (buff == K_DEL_FOREWARD)
		apply_del_foreward(command_line);
	if (shift_flag == TRUE)
		update_select(command_line, buff);
	refresh_command_line(command_line);
}
