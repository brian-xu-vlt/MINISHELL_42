#include "line_editor_bonus.h"


void	init_prompt(void)
{
	t_le	*le;

	le = get_struct(GET);
	print_prompt();
	if (le->prompt_len >= le->scols)
		exit_routine_le(ERR_SCREEN_SIZE);
	le->cx = (int)le->prompt_len;
	le->cy = 0;
	le->vct_index = 0;
	vct_clear(le->cmd_line);
}
