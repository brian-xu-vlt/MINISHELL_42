#include "line_editor_bonus.h"

int		is_shift_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_SHIFT);
}

int		is_ctrl_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_CTRL);
}

int		is_ctrl_shift_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_CTRL_SHIFT);
}

int		ms_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

t_le	*get_struct(t_le *mem)
{
	static t_le	*mem_backup = NULL;

	if (mem != NULL)
		mem_backup = mem;
	else if (mem == NULL && mem_backup == NULL)
		exit_routine_le(ERR_MALLOC);
	return (mem_backup);
}

/*
**	Not used but stored here to integrate libft
*/

char	*vct_getstrat(t_vector *vct, size_t index)
{
	if (vct == NULL || vct->str == NULL || index > vct_getlen(vct))
		return (NULL);
	return (vct->str + index);
}
