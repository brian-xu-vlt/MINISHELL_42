#include "line_editor_bonus.h"

static int		fill_struct(void)
{
	int		i;

	i = 0;
	g_le.termcap[VISIBLE_CURSOR] = tgetstr("vi", NULL);
	g_le.termcap[HIDE_CURSOR] = tgetstr("cd", NULL);
	g_le.termcap[INSERT_MODE] = tgetstr("im", NULL);
	g_le.termcap[NORMAL_MODE] = tgetstr("ei", NULL);
	g_le.termcap[SELECT] = tgetstr("so", NULL);
	g_le.termcap[UNSELECT] = tgetstr("se", NULL);
	g_le.termcap[CLEAR_AFTER_CURSOR] = tgetstr("cd", NULL);
	g_le.termcap[SAVE_CURSOR_POS] = tgetstr("sc", NULL);
	g_le.termcap[RESTORE_CURSOR_POS] = tgetstr("rc", NULL);
	while (i < NB_TERMCAP)
	{
		if (g_le.termcap[i] == NULL)
			exit_routine_le(ERR_TERMCAP);
		i++;
	}
	return (SUCCESS);
}

void			init_termcaps(void)
{
	int		ret;
	char	*term_name;

	term_name = getenv("TERM"); // to be changed to use main char *env[]
	if (term_name == NULL)
		exit_routine_le(ERR_TERM_NAME);
	ret = tgetent(NULL, term_name);
	if (ret != TRUE)
		exit_routine_le(ERR_TERMCAP);
	fill_struct();
}

