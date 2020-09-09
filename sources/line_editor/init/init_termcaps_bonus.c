#include "line_editor_bonus.h"

static int		fill_struct(t_le* le)
{
	int		i;

	i = 0;
	le->termcap[VISIBLE_CURSOR] = tgetstr("vi", NULL);
	le->termcap[HIDE_CURSOR] = tgetstr("cd", NULL);
	le->termcap[INSERT_MODE] = tgetstr("im", NULL);
	le->termcap[NORMAL_MODE] = tgetstr("ei", NULL);
	le->termcap[SELECT] = tgetstr("so", NULL);
	le->termcap[UNSELECT] = tgetstr("se", NULL);
	le->termcap[CLEAR_AFTER_CURSOR] = tgetstr("cd", NULL);
	le->termcap[SAVE_CURSOR_POS] = tgetstr("sc", NULL);
	le->termcap[RESTORE_CURSOR_POS] = tgetstr("rc", NULL);
	while (i < NB_TERMCAP)
	{
		if (le->termcap[i] == NULL)
			exit_routine_le(ERR_TERMCAP);
		i++;
	}
	return (SUCCESS);
}

void			init_termcaps(void)
{
	int		ret;
	char	*term_name;
	t_le	*le;

	term_name = getenv("TERM"); // to be changed to use main char *env[]
	if (term_name == NULL)
		exit_routine_le(ERR_TERM_NAME);
	ret = tgetent(NULL, term_name);
	if (ret != TRUE)
		exit_routine_le(ERR_TERMCAP);
	le = (t_le *)malloc(sizeof(t_le));
	get_env(le);
	fill_struct(le);
}

