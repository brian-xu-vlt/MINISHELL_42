#include "line_editor_bonus.h"

static void	init_library_db(void)
{
	int			ret;
	//const char	*term_name = "xterm-256color";
	const char	*term_name;

	term_name = getenv("TERM"); // to be changed MINISHELL get env !!!!!!!
	if (term_name == NULL)
		exit_routine_le(ERR_TERM_NAME);
	if (ft_strequ((char *)term_name, "ansi") == TRUE)
		exit_routine_le(ERR_TERMCAP);
	ret = tgetent(NULL, term_name);
	if (ret != TRUE)
		exit_routine_le(ERR_TERMCAP);
}

static void	fill_termcaps(t_le *le)
{
	int		i;

	le->termcap[CLEAR_ALL_AFTER_CURS] = tgetstr("cd", NULL);
	le->termcap[SELECT] = tgetstr("so", NULL);
	le->termcap[UNSELECT] = tgetstr("se", NULL);
	le->termcap[MOVE_CURSOR_HOME] = tgetstr("ho", NULL);
	le->termcap[ONE_COL_LEFT] = tgetstr("le", NULL);
	le->termcap[ONE_COL_RIGHT] = tgetstr("nd", NULL);
	le->termcap[ONE_ROW_DOWN] = tgetstr("do", NULL);
	le->termcap[ONE_ROW_UP] = tgetstr("up", NULL);
	le->termcap[MOVE_X_ROWS_UP] = tgetstr("UP", NULL);
	le->termcap[RETURN_CARRIAGE] = tgetstr("cr", NULL);
	le->termcap[MOVE_AT_COL_X] = tgetstr("ch", NULL);
	le->termcap[VISIBLE_CURSOR] = tgetstr("ve", NULL);
	le->termcap[HIDE_CURSOR] = tgetstr("vi", NULL);
	le->termcap[SCROLLING_CAPABILITY] = tgetstr("sf", NULL);
	i = 0;
	while (i < NB_ESSENTIAL_TERMCAP)
	{
		if (le->termcap[i] == NULL)
			exit_routine_le(ERR_TERMCAP);
		i++;
	}
}

void		init_line_editor(t_vector *cmd_line)
{
	t_le	*le;

	le = (t_le *)ft_calloc(1, sizeof(t_le));
	get_struct(le);
	if (le == NULL)
		exit_routine_le(ERR_MALLOC);
	le->prompt_len = ft_strlen(PROMPT);
	le->clipboard = vct_new();
	if (le->clipboard == NULL)
		exit_routine_le(ERR_MALLOC);
	le->cmd_line = cmd_line;
	if (DEBUG_MODE == 0)
	{
		init_library_db();
		init_term_mode();
		fill_termcaps(le);
		update_window_size();
	}
}
