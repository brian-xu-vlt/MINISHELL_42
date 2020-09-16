#include "line_editor_bonus.h"


/*

static void	apply_key(long buff)
{
	static t_key_process		key_process[NB_KEY] = {up_key, down_key,
									left_key, right_key, space_key, escape_key,
									backspace_key, del_key, return_key,
									right_key};
	static const long			key_code[NB_KEY] = {KEY_UP, KEY_DOWN, KEY_LEFT,
									KEY_RIGHT, KEY_SPACE, KEY_ESCAPE,
									KEY_BACKSPACE, KEY_DEL, KEY_RETURN,
									KEY_TAB};
	size_t						i;

	i = 0;
	while (i < NB_KEY)
	{
		if (mask == key_code[i])
		{
			key_process[i]();
			break ;
		}
		i++;
	}
}

*/

static long	strip_off_extra_bits(long buff)
{
	return ((buff & ((long)0xff << 40)) >> 24 | (buff & 0xffff)); 
}

static void	dispatch_esc_sequence(long buff)
{
	int	k_mask;

	k_mask = 0;
	k_mask |= (is_ctrl_shift_on(buff) == TRUE) ? (CTRL_MASK | SHIFT_MASK) : 0;
	k_mask |= (is_ctrl_on(buff) == TRUE) ? CTRL_MASK : 0;
	k_mask |= (is_shift_on(buff) == TRUE) ? SHIFT_MASK : 0;
	if (k_mask != 0)
		buff = strip_off_extra_bits(buff);

	if ((k_mask & CTRL_MASK) && buff == K_RIGHT)
		move_one_word_right();
	else if ((k_mask & CTRL_MASK) && buff == K_LEFT)
		move_one_word_left();
	else if ((k_mask & CTRL_MASK) && buff == K_UP)
		cut_selection();

	else if ((k_mask & SHIFT_MASK) && buff == K_UP)
		copy_selection();
	else if ((k_mask & SHIFT_MASK) && buff == K_DOWN)
		past_clipboard();

	else if (buff == K_DEL_BACKWARD || buff == K_DEL_FOREWARD)
		delete_selection(buff);
	else if (buff == K_UP || buff == K_DOWN)
		call_history(buff);
	else if (buff == K_LEFT)
		move_cursor_left();
	else if (buff == K_RIGHT)
		move_cursor_right();
	else if (buff == K_HOME)
		move_start_of_line();
	else if (buff == K_END)
		move_end_of_line();

	if ((k_mask & SHIFT_MASK) == FALSE)
		unselect_all();	
	else if ((k_mask & SHIFT_MASK) && buff != K_DOWN)
		update_selection(buff);

	refresh();
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

int			handle_esc_seq(char buff)
{
	long	long_buff;

	if (buff != K_DEL_BACKWARD)
		long_buff = expand_escape_sequence(buff);
	else
		long_buff = (long)buff;
	dispatch_esc_sequence(long_buff);	
	return (CONTINUE);
}
