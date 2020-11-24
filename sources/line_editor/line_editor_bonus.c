#include "line_editor_bonus.h"

static int	line_editor_loop(t_le *le)
{
	char	key;
	int		ret_read;

	ret_read = SUCCESS;
	while ((ret_read = read(STDIN_FILENO, &key, 1)) > 0)
	{
		update_window_size();
		ms_tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		le->vct_index_backup = le->vct_index;
		if (key == K_EOF && vct_getlen(le->cmd_line) == 0)
			exit_routine_le("exit");									// check return value of Minishell ?
		if (key == K_ENTER)
			break ;
		if (ft_isprint(key) == TRUE)
			handle_print_char(key);
		else
			handle_esc_seq(key);
		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	return (ret_read);
}

int			line_editor(void)
{
	t_le	*le;
	int		ret_read;

	le = get_struct(GET);
	set_termios(le->termios_editor);
	update_window_size();
	init_prompt();
	init_selection();
	ret_read = line_editor_loop(le);
	if (le->cmd_line_backup != NULL)
	{
		free(le->cmd_line_backup);
		le->cmd_line_backup = NULL;
	}
	unselect_all();
	move_cursor_at_index(vct_getlen(le->cmd_line));
	save_history();
	set_termios(le->termios_bkup);
	return (ret_read);
}
