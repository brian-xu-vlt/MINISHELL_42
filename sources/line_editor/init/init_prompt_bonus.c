#include "line_editor_bonus.h"

void	init_prompt()
{
	g_le.prompt_len = ft_strlen(PROMPT);
	ft_putstr_fd(PROMPT, STDERR_FILENO);
	if (g_le.scols <= g_le.prompt_len)
		exit_routine_le(ERR_SCREEN_SIZE);
	g_le.cx = (int)g_le.prompt_len;
	g_le.cy = 0;
	g_le.vct_index = 0;
}
