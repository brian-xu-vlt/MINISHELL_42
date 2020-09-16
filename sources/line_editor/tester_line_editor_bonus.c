#include "line_editor_bonus.h"

/***********************************************
**********TEST UNITAIRE FOR LINE EDITOR.c*******
***********************************************/

int 	main(void)
{
	t_le	*le;

	init_minishell();
	le = get_env(GET);
	le->cmd_line = vct_new();
	while (ft_strncmp(vct_getstr(le->cmd_line), "quit", 5) != 0)
	{
		vct_clear(le->cmd_line);
		line_editor();
		ft_printf("\n%s|%s|\n", PROMPT, vct_getstr(le->cmd_line));
	}
	vct_del(&le->cmd_line);
	return (0);	
}
