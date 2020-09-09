#include "line_editor_bonus.h"

int		ft_iscntrl(char c)
{
	return ((c <= 27) || (c == 127));
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

size_t	convert_cur_pos_vctindex(int cx, int cy)
{
	return ((cy * g_le.scols) + cx - g_le.prompt_len);
}

void	convert_vctindex_cur_pos(int vct_index)
{
	g_le.cy = (vct_index + g_le.prompt_len - 1) / g_le.scols;
	g_le.cx = vct_index + g_le.prompt_len -  1 - (g_le.cy * g_le.scols);
}
