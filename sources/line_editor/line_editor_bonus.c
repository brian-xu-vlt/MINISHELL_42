#include "line_editor_bonus.h"

void		debug_test_command_3(void)
{
	int		i;

	i = 0;
	while (i < 100)
	{
		ft_putstr_fd(ft_itoa(i), STDERR_FILENO);
		move_cursor_left();
		i++;
	}

}

void		debug_test_command_2(void)
{
	char 	*buff_1;

	buff_1 = tparm(tgetstr("sr", NULL), 1);
	tputs(buff_1, 1, ms_putchar);
}

void		debug_test_command_1(void)
{
	t_le	*le;
	char 	*buff_1;

	le = get_env(GET);
	buff_1 = tparm(le->termcap[MOVE_AT_COL_X], 0);
	tputs(buff_1, 1, ms_putchar);
	buff_1 = tparm(le->termcap[MOVE_X_ROWS_UP], (le->cy > le->srows - 1) ? le->cy : le->srows);
	tputs(buff_1, le->srows, ms_putchar); 
}

void		line_editor(t_vector *command_line)
{
	char	buff[L_ED_BUFF_SIZE];
	int		ret;

	if (command_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	update_window_size();
	init_prompt();
	init_selection();
	ft_bzero(buff, L_ED_BUFF_SIZE);
	while((ret = read(STDIN_FILENO, buff, L_ED_BUFF_SIZE - 1)) >= 0)
	{
/*		if (*buff == '1')
			debug_test_command_1();
		else if (*buff == '2')
			debug_test_command_2();
		else if (*buff == '3')
			debug_test_command_3();
*/		if (*buff == K_ENTER)
		{
			unselect_all(command_line);
			move_cursor_at_index(command_line, vct_getlen(command_line));
			return ;
		}
		else if (ft_isprint(*buff) == FALSE)
			handle_esc_seq(*(long *)buff, command_line);
		else if (ft_isprint(*buff) == TRUE)
			handle_print_char(buff[0], command_line);
		ft_bzero(buff, L_ED_BUFF_SIZE);
		if (DEBUG == TRUE)
			debug_print_infos(command_line);
	}
}
