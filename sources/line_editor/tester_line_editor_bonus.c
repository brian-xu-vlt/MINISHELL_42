#include "line_editor_bonus.h"

/***********************************************
********** MAIN TEST  FOR LINE EDITOR.c  *******
***********************************************/

int 	main(void)
{
	t_le	*le;

	init_minishell();
	le = get_env(GET);
	while (ft_strncmp(vct_getstr(le->cmd_line), "quit", 5) != 0)
	{
		vct_clear(le->cmd_line);
		line_editor();
		save_history();
		ft_printf("\n%s|%s|\n", PROMPT, vct_getstr(le->cmd_line));
		if (ft_strncmp(vct_getstr(le->cmd_line), "history", 8) == 0)
			print_history();
	}
	if (le->cmd_line != NULL)
		vct_del(&le->cmd_line);
	if (le->clipboard != NULL)
		vct_del(&le->clipboard);
	free_history();
	return (0);
}
