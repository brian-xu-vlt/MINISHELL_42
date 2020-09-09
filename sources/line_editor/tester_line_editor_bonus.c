#include "line_editor_bonus.h"

/***********************************************
**********TEST UNITAIRE FOR LINE EDITOR.c*******
***********************************************/

int 	main(void)
{
	t_vector	*test_command;

	init_termcaps();
	init_term_mode();
	update_window_size();

	test_command = vct_new();

	while (ft_strncmp(vct_getstr(test_command), "quit", 5) != 0)
	{
		vct_clear(test_command);
		line_editor(test_command);
		printf("\n==|%s|\n", vct_getstr(test_command));
	}
	vct_del(&test_command);
	return (0);	
}
