#include "line_editor_bonus.h"

static int		fill_struct(t_le* line_editor_struct)
{
	int		i;

	i = 0;
	line_editor_struct.termcap[VISIBLE_CURSOR] = tgetstr("vi", NULL);
	line_editor_struct.termcap[HIDE_CURSOR] = tgetstr("cd", NULL);
	line_editor_struct.termcap[INSERT_MODE] = tgetstr("im", NULL);
	line_editor_struct.termcap[NORMAL_MODE] = tgetstr("ei", NULL);
	line_editor_struct.termcap[SELECT] = tgetstr("so", NULL);
	line_editor_struct.termcap[UNSELECT] = tgetstr("se", NULL);
	line_editor_struct.termcap[CLEAR_AFTER_CURSOR] = tgetstr("cd", NULL);
	line_editor_struct.termcap[SAVE_CURSOR_POS] = tgetstr("sc", NULL);
	line_editor_struct.termcap[RESTORE_CURSOR_POS] = tgetstr("rc", NULL);
	while (i < NB_TERMCAP)
	{
		if (line_editor_struct.termcap[i] == NULL)
			exit_routine_le(ERR_TERMCAP);
		i++;
	}
	return (SUCCESS);
}

void			init_termcaps(void)
{
	int		ret;
	char	*term_name;
	t_le	*line_editor_struct;

	term_name = getenv("TERM"); // to be changed to use main char *env[]
	if (term_name == NULL)
		exit_routine_le(ERR_TERM_NAME);
	ret = tgetent(NULL, term_name);
	if (ret != TRUE)
		exit_routine_le(ERR_TERMCAP);
	line_editor_struct = (t_le *)malloc(sizeof(t_le));
	get_env(line_editor_struct);
	fill_struct(line_editor_struct);
}

