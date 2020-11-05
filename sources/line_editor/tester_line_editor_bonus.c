#include "line_editor_bonus.h"

/***********************************************
********** MAIN TEST  FOR LINE EDITOR.c  *******
***********************************************/

/*
**	HERE : the no-bonus reading loop
*/

int		main(int ac, char **av, char **envp)
{
	t_le	*le;

	init_minishell();
	le = get_struct(GET);
	init_env(envp);
	(void)ac;
	(void)av;
	while (ft_strncmp(vct_getstr(le->cmd_line), "quit", 5) != 0)
	{
		vct_clear(le->cmd_line);
		line_editor();
		save_history();
	

		if (ft_strncmp(vct_getstr(le->cmd_line), "history", 8) == 0)
			print_history();
		}
	exit_routine_le(NULL);
	return (0);
}
