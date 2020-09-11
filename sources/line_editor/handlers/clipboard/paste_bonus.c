#include "line_editor_bonus.h"

void	past_clipboard(t_vector *command_line)
{
	int		i;
	t_le	*le;
	char	*clipboard_content;

	le = get_env(GET);
	unselect_all(command_line);
	clipboard_content = vct_getstr(le->clipboard);	
	i = 0;
	while (clipboard_content[i] != '\0')
	{
		insert_char_in_vct(command_line, clipboard_content[i]);
		move_cursor_right(command_line);
		i++;
	}
}
