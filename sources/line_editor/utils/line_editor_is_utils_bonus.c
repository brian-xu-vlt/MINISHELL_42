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
