#include "line_editor_bonus.h"

void	past_clipboard(t_vector *command_line)
{
	int		clipboard_len;
	int		i;
	char	clipboard_content;
	t_le	*le;

	le = get_env(GET);
	unselect_all(command_line);
	clipboard_len = vct_getlen(le->clipboard);
	i = 0;
	while (i < clipboard_len)
	{
		clipboard_content = vct_getcharat(le->clipboard, i);
		insert_char_in_vct(command_line, clipboard_content);
		move_cursor_right(command_line);
		i++;
	}
}
