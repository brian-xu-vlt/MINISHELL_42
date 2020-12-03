#include "minishell.h"

static void	init_library_db(void)
{
	int			ret;
	const char	*term_name;

	term_name = vct_getstr(get_env_value_vct(get_env_list(GET), "TERM"));
	if (term_name == NULL)
		exit_routine(EXIT_TERM_NAME);
	if (ft_strequ((char *)term_name, "xterm-256color") == false)
		exit_routine(EXIT_TERMCAP);
	ret = tgetent(NULL, term_name);
	if (ret != true)
		exit_routine(EXIT_TERMCAP);
}

static char	*get_termcap_str(const char *capability)
{
	char		*ret;

	ret = tgetstr(capability, NULL);
	if (ret == NULL)
		exit_routine(EXIT_TERMLIB);
	return (ret);
}

static void	fill_termcaps(t_le *le)
{
	le->termcap[CLEAR_LINE] = get_termcap_str("ce");
	le->termcap[CLEAR_ALL_AFTER_CURS] = get_termcap_str("cd");
	le->termcap[SELECT] = get_termcap_str("so");
	le->termcap[UNSELECT] = get_termcap_str("se");
	le->termcap[MOVE_CURSOR_HOME] = get_termcap_str("ho");
	le->termcap[ONE_COL_LEFT] = get_termcap_str("le");
	le->termcap[ONE_COL_RIGHT] = get_termcap_str("nd");
	le->termcap[ONE_ROW_DOWN] = get_termcap_str("do");
	le->termcap[ONE_ROW_UP] = get_termcap_str("up");
	le->termcap[MOVE_X_ROWS_UP] = get_termcap_str("UP");
	le->termcap[CURSOR_POSITION_REQUEST] = get_termcap_str("u7");
	le->termcap[RETURN_CARRIAGE] = get_termcap_str("cr");
	le->termcap[MOVE_AT_COL_X] = tgetstr("ch", NULL);
	le->termcap[VISIBLE_CURSOR] = tgetstr("ve", NULL);
	le->termcap[HIDE_CURSOR] = tgetstr("vi", NULL);
	le->termcap[SCROLLING_CAPABILITY] = tgetstr("sf", NULL);
}

t_le		*init_line_editor(t_vector *cmd_line)
{
	t_le	*le;

	le = (t_le *)ft_calloc(1, sizeof(t_le));
	if (le == NULL)
		exit_routine(EXIT_MALLOC);
	get_struct(le);
	le->prompt_len = ft_strlen(PROMPT_LINE_EDITION);
	le->clipboard = safe_vct_new();
	le->cmd_line = cmd_line;
	if (DEBUG_MODE == FALSE)
	{
		init_library_db();
		init_term_mode();
		fill_termcaps(le);
		update_window_size();
	}
	return (le);
}
