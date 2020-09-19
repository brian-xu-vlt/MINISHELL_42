#include "line_editor_bonus.h"

/***********************************************
********** MAIN TEST  FOR LINE EDITOR.c  *******
***********************************************/

/*
**	HERE : the no-bonus reading loop
*/

int		main(int ac, char **av, char **env)
{
	t_le	*le;

	init_minishell();
	le = get_struct(GET);
	init_env(env);
	(void)ac;
	(void)av;
	while (ft_strncmp(vct_getstr(le->cmd_line), "quit", 5) != 0)
	{
		vct_clear(le->cmd_line);
		line_editor();
		save_history();
		ft_printf("\n%s|%s|\n", PROMPT, vct_getstr(le->cmd_line));
		if (ft_strncmp(vct_getstr(le->cmd_line), "history", 8) == 0)
			print_history();
		if (ft_strncmp(vct_getstr(le->cmd_line), "env", 8) == 0)
			print_env(ALL);
	}
	exit_routine_le(NULL);
	return (0);
}
