#include "line_editor_bonus.h"

static long	strip_off_extra_bits(long buff)
{
	return ((buff & ((long)0xff << 40)) >> 24 | (buff & 0xffff)); 
}

static void	dispatch_esc_sequence(long buff, t_vector *command_line)
{
	int	keys_mask;

	keys_mask = 0;
	int	shift_flag;
	int	ctrl_flag;

	shift_flag = FALSE;
	ctrl_flag = FALSE;

	if (is_ctrl_shift_on(buff) == TRUE)
	{
		buff = strip_off_extra_bits(buff);
		shift_flag = TRUE;
		ctrl_flag = TRUE;
	}
	else if ((shift_flag = is_shift_on(buff)) == TRUE)
		buff = strip_off_extra_bits(buff);
	else if ((ctrl_flag = is_ctrl_on(buff)) == TRUE)
		buff = strip_off_extra_bits(buff);

	if (ctrl_flag == TRUE && buff == K_RIGHT)
		move_one_word_right(command_line);
	else if (ctrl_flag == TRUE && buff == K_LEFT)
		move_one_word_left(command_line);
	else if (ctrl_flag == TRUE && buff == K_UP)
		cut_selection(command_line);

	else if (shift_flag == TRUE && buff == K_UP)
		copy_selection(command_line);
	else if (shift_flag == TRUE && buff == K_DOWN)
		past_clipboard(command_line);

	else if (buff == K_UP || buff == K_DOWN)
		call_history(buff);
	else if (buff == K_LEFT)
		move_cursor_left();
	else if (buff == K_RIGHT)
		move_cursor_right(command_line);
	else if (buff == K_HOME)
		move_start_of_line();
	else if (buff == K_END)
		move_end_of_line(command_line);
	else if (buff == K_DEL_BACKWARD)
		delete_selection(command_line, buff);
	else if (buff == K_DEL_FOREWARD)
		delete_selection(command_line, buff);

	if (shift_flag == FALSE)
		unselect_all(command_line);	
	else if (shift_flag == TRUE && buff != K_DOWN)
		update_selection(command_line, buff);

	refresh_command_line(command_line);
}

static long	expand_escape_sequence(char buff)
{
	long	long_buff;

	long_buff = 0;
	if (read(STDIN_FILENO, &long_buff, sizeof(long) - 1) != FAILURE)
	{
		long_buff = (long_buff << 8) | buff;	
		return (long_buff);
	}
	return (0);
}

int			handle_esc_seq(char buff, t_vector *command_line)
{
	long	long_buff;

	if (buff != K_DEL_BACKWARD)
		long_buff = expand_escape_sequence(buff);
	else
		long_buff = (long)buff;
	dispatch_esc_sequence(long_buff, command_line);	
	return (CONTINUE);
}
