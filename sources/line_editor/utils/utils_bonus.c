#include "line_editor_bonus.h"

int		ft_iscntrl(char c)
{
	return ((c <= 27) || (c == 127));
}

int			is_shift_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_SHIFT);
}

int		ms_putchar(int c)
{
	return (write(1, &c, 1));
}


/*
int	get_ctrlkey(int c)
{
	// stips the CTRL part of the int in order to compare with simple letter
	// so basically: c == ctrl+c ?
	return (c & 0x1f);
}
*/

t_le				*get_env(t_le *env)
{
	static t_env *env_backup = NULL;

	if (env != NULL)
		env_backup = env;
	return (env_backup);
}
