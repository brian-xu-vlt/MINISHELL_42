#include "line_editor_bonus.h"

void	init_prompt(void)
{
	t_le	*le;

	le = get_struct(GET);
	ft_putstr_fd(PROMPT, STDOUT_FILENO);
	if (le->prompt_len >= le->scols)
		exit_routine_le(ERR_SCREEN_SIZE);
	le->cx = (int)le->prompt_len;
	le->cy = 0;
	le->vct_index = 0;
	vct_clear(le->cmd_line);
}
/*
		SIGABRT, SIGINT, SIGQUIT, SIGCHLD, SIGWINCH
	};
	static void 	(*handlers_mode_normal[sig_nb])(int) = {
		SIG_DFL, sigint_normal_mode, display_signal, SIG_DFL, window_signal
	};
	static void 	(*handlers_mode_exec[sig_nb])(int) = {
		display_signal, display_signal, display_signal, SIG_DFL, SIG_DFL
	};
*/
