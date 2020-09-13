#include "line_editor_bonus.h"

static void	init_library_db(void)
{
	int				ret;
	char			*term_name;

	term_name = getenv("TERM"); // to be changed to use main char *env[]
	if (term_name == NULL)
		exit_routine_le(ERR_TERM_NAME);
	ret = tgetent(NULL, term_name);
	if (ret != TRUE)
		exit_routine_le(ERR_TERMCAP);
}

static int		fill_termcaps(t_le* le)
{
	int		i;

	le->termcap[MOVE_CURSOR_HOME] = tgetstr("ho", NULL);
	le->termcap[SAVE_CURSOR_POS] = tgetstr("sc", NULL);
	le->termcap[RESTORE_CURSOR_POS] = tgetstr("rc", NULL);
	le->termcap[CLEAR_ALL_AFTER_CURS] = tgetstr("cd", NULL);
	le->termcap[ONE_COL_LEFT] = tgetstr("le", NULL);
	le->termcap[ONE_COL_RIGHT] = tgetstr("nd", NULL);
	le->termcap[ONE_ROW_DOWN] = tgetstr("do", NULL);
	le->termcap[ONE_ROW_UP] = tgetstr("up", NULL);
	le->termcap[DELETE_ONE_CHAR] = tgetstr("dc", NULL);
	le->termcap[HIDE_CURSOR] = tgetstr("vi", NULL);
	le->termcap[VISIBLE_CURSOR] = tgetstr("ve", NULL);
	le->termcap[IN_INSERT_MODE] = tgetstr("im", NULL);
	le->termcap[OUT_INSERT_MODE] = tgetstr("ei", NULL);
	le->termcap[SELECT] = tgetstr("so", NULL);
	le->termcap[UNSELECT] = tgetstr("se", NULL);
	le->termcap[MOVE_AT_COL_X] = tgetstr("ch", NULL);
	le->termcap[MOVE_X_ROWS_UP] = tgetstr("UP", NULL);
	i = 0;
	while (i < NB_TERMCAP)
	{
		if (le->termcap[i] == NULL)
			exit_routine_le(ERR_TERMCAP);
		i++;
	}
	return (SUCCESS);
}

void			init_minishell(void)
{
	t_le	*le;

	le = (t_le *)malloc(sizeof(t_le));
	get_env(le);
	if (le == NULL)
		exit_routine_le(ERR_MALLOC);
	le->prompt_len = ft_strlen(PROMPT);
	le->clipboard = vct_new();
	le->vct_history = NULL;
	le->vct_command_line_backup = NULL;
	if (le->clipboard == NULL)
		exit_routine_le(ERR_MALLOC);
	vct_clear(le->clipboard);
	init_library_db();
	init_term_mode();
	fill_termcaps(le);
	update_window_size();
}
