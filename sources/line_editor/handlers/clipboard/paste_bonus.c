#include "line_editor_bonus.h"

void	past_clipboard(void)
{
	int		clipboard_len;
	int		i;
	char	clipboard_content;
	t_le	*le;

	le = get_env(GET);
	unselect_all();
	clipboard_len = vct_getlen(le->clipboard);
	i = 0;
	while (i < clipboard_len)
	{
		clipboard_content = vct_getcharat(le->clipboard, i);
		insert_char_in_vct(clipboard_content);
		move_cursor_right();
		i++;
	}
}
