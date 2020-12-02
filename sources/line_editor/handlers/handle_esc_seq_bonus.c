#include "minishell.h"

static long	strip_off_extra_bits(long key)
{
	return ((key & ((long)0xff << 40)) >> 24 | (key & 0xffff));
}

static void	dispatch_simple_keys(long key)
{
	if (key == K_DEL_BACKWARD || key == K_DEL_FOREWARD)
		delete_selection(key);
	else if (key == K_UP || key == K_DOWN)
		call_history(key);
	else if (key == K_LEFT)
		move_cursor_left();
	else if (key == K_RIGHT)
		move_cursor_right();
	else if (key == K_HOME)
		move_start_of_line();
	else if (key == K_END)
		move_end_of_line();
}

static void	dispatch_esc_sequence(long key)
{
	int	k_mask;

	k_mask = 0;
	k_mask |= (is_ctrl_shift_on(key) == TRUE) ? (CTRL_MASK | SHIFT_MASK) : 0;
	k_mask |= (is_ctrl_on(key) == TRUE) ? CTRL_MASK : 0;
	k_mask |= (is_shift_on(key) == TRUE) ? SHIFT_MASK : 0;
	if (k_mask != 0)
		key = strip_off_extra_bits(key);
	if ((k_mask & CTRL_MASK) && key == K_RIGHT)
		move_one_word_right();
	else if ((k_mask & CTRL_MASK) && key == K_LEFT)
		move_one_word_left();
	else if ((k_mask & CTRL_MASK) && key == K_UP)
		cut_selection();
	else if ((k_mask & SHIFT_MASK) && key == K_UP)
		copy_selection();
	else if ((k_mask & SHIFT_MASK) && key == K_DOWN)
		past_clipboard();
	else
		dispatch_simple_keys(key);
	if ((k_mask & SHIFT_MASK) == FALSE)
		unselect_all();
	else if ((k_mask & SHIFT_MASK) && key != K_DOWN)
		update_selection(key);
	refresh_command_line();
}

static long	expand_escape_sequence(char key)
{
	long	long_key;

	long_key = 0;
	if (read(STDIN_FILENO, &long_key, sizeof(long) - 1) != FAILURE)
	{
		long_key = (long_key << 8) | key;
		return (long_key);
	}
	return (0);
}

void		handle_esc_seq(char key)
{
	long	long_key;

	if (key == K_TAB)
		return ;
	else if (key != K_DEL_BACKWARD)
		long_key = expand_escape_sequence(key);
	else
		long_key = (long)key;
	dispatch_esc_sequence(long_key);
}
