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
		test(le->cmp_line);
	

		if (ft_strncmp(vct_getstr(le->cmd_line), "history", 8) == 0)
			print_history();
		}
	exit_routine_le(NULL);
	return (0);
}

/*
	if (ft_strncmp(vct_getstr(le->cmd_line), "env", 4) == 0)
			print_env(ALL);
		if (ft_strncmp(vct_getstr(le->cmd_line), "e", 2) == 0)
			print_env("test");
		if (ft_strncmp(vct_getstr(le->cmd_line), "1", 2) == 0)
			store_env("test", "42");
		if (ft_strncmp(vct_getstr(le->cmd_line), "2", 2) == 0)
			store_env("test", "21");
		if (ft_strncmp(vct_getstr(le->cmd_line), "3", 2) == 0)
			store_env("test2", "1337");
		if (ft_strncmp(vct_getstr(le->cmd_line), "4", 2) == 0)
			store_env("t", "1337");
		if (ft_strncmp(vct_getstr(le->cmd_line), "5", 2) == 0)
			delete_env("t");
		if (ft_strncmp(vct_getstr(le->cmd_line), "6", 2) == 0)
			store_env("test", "");
		if (ft_strncmp(vct_getstr(le->cmd_line), "7", 2) == 0)
			store_env("LC_TERMINAL_VERSION", "");
*/
