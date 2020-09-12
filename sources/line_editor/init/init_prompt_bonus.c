#include "line_editor_bonus.h"

void	init_prompt()
{
	t_le	*le;

	le = get_env(GET);
	ft_putstr_fd(PROMPT, STDERR_FILENO);
	if (le->scols <= le->prompt_len)
		exit_routine_le(ERR_SCREEN_SIZE);
	le->cx = (int)le->prompt_len;
	le->cy = 0;
	le->vct_index = 0;
}
