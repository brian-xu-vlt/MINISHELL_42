#include "line_editor_bonus.h"

static void		line_editor_loop(t_le *le)
{
	char	key;

	while (read(STDIN_FILENO, &key, 1) != FAILURE && key != K_ENTER)
	{
		update_window_size();
		ms_tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		le->vct_index_backup = le->vct_index;
		if (key == K_EOF && vct_getlen(le->cmd_line) == 0)
			exit_routine_le("exit");
		if (ft_isprint(key) == TRUE)
			handle_print_char(key);
		else
			handle_esc_seq(key);
		if (DEBUG_MODE == TRUE)
			debug_print_infos();
		ms_tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
}

void			line_editor(void)
{
	t_le	*le;

	le = get_struct(GET);
	set_termios(le->termios_editor);
	update_window_size();
	init_prompt();
	init_selection();
	line_editor_loop(le);
	if (le->cmd_line_backup != NULL)
	{
		free(le->cmd_line_backup);
		le->cmd_line_backup = NULL;
	}
	unselect_all();
	move_cursor_at_index(vct_getlen(le->cmd_line));
	save_history();
	set_termios(le->termios_bkup);
}
