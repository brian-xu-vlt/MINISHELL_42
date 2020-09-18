#include "line_editor_bonus.h"

static void		line_editor_loop(void)
{
	char	key;
	t_le	*le;

	le = get_env(GET);
	while (read(STDIN_FILENO, &key, 1) != FAILURE && key != K_ENTER)
	{
		tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		le->vct_index_backup = le->vct_index;
		if (ft_isprint(key) == TRUE)
			handle_print_char(key);
		else
			handle_esc_seq(key);
		if (DEBUG == TRUE)
			debug_print_infos();
		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
}

void			line_editor(void)
{
	t_le	*le;

	le = get_env(GET);
	if (le->cmd_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	update_window_size();
	init_prompt();
	init_selection();
	line_editor_loop();
	if (le->cmd_line_backup != NULL)
	{
		free(le->cmd_line_backup);
		le->cmd_line_backup = NULL;
	}
	unselect_all();
	move_cursor_at_index(vct_getlen(le->cmd_line));
}
