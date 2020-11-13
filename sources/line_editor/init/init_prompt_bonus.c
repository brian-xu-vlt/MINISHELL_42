#include "line_editor_bonus.h"

void	print_line_editor_prompt(void)
{
	if (ft_putstr_fd(PROMPT, STDOUT_FILENO) == -1)
		ft_putstr_fd(PROMPT, STDERR_FILENO);
}

void	init_prompt(void)
{
	t_le	*le;

	le = get_struct(GET);
	print_line_editor_prompt();
	if (le->prompt_len >= le->scols)
		exit_routine_le(ERR_SCREEN_SIZE);
	le->cx = (int)le->prompt_len;
	le->cy = 0;
	le->vct_index = 0;
	vct_clear(le->cmd_line);
}
