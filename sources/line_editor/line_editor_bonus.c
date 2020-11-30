#include "minishell_bonus.h"

static int	line_editor_loop(t_le *le)
{
	char	key;
	int		ret_read;

	ret_read = SUCCESS;
	while ((ret_read = read(STDIN_FILENO, &key, 1)) > 0 && key != K_ENTER)
	{
		ms_tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		le->vct_index_backup = le->vct_index;
		if (key == K_EOF && vct_getlen(le->cmd_line) == 0)
			exit_routine(EXIT_NORMAL);									// TODO: check return value of Minishell ?
		if (ft_isprint(key) == TRUE)
			handle_print_char(key);
		else
			handle_esc_seq(key);
		ms_tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
	return (ret_read);
}

int			line_editor(void)
{
	t_le	*le;
	int		ret_read;

	le = get_struct(GET);
	set_termios(le->termios_editor);
	init_prompt();
	init_selection();
	ret_read = line_editor_loop(le);
	if (le->cmd_line_backup != NULL)
	{
		free(le->cmd_line_backup);
		le->cmd_line_backup = NULL;
	}
	move_end_of_line();
	unselect_all();
	save_history();
	set_termios(le->termios_bkup);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (ret_read);
}
