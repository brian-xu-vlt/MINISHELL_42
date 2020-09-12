#include "line_editor_bonus.h"
/*
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
	char *buff;
	t_le *le;
	le = get_env(GET);
	if (le->cx >= le->scols - 1)
	{
		buff = tparm(le->termcap[MOVE_AT_COL_X], 0);
		tputs(buff, 2, ms_putchar);
		tputs(le->termcap[ONE_ROW_DOWN], 1, ms_putchar);
		le->cx = 0;
		le->cy++;
	}
	else
	{
		tputs(le->termcap[ONE_COL_RIGHT], 1, ms_putchar);
		le->cx++;
	}
	le->vct_index++;
}
*/

void		line_editor(t_vector *command_line)
{
	char	buff[L_ED_BUFF_SIZE];
	int		ret;
	t_le	*le;

	if (command_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	le = get_env(GET);
	update_window_size();
	init_prompt();
	init_selection();
	ft_bzero(buff, L_ED_BUFF_SIZE);
	while((ret = read(STDIN_FILENO, buff, L_ED_BUFF_SIZE - 1)) >= 0)
	{
		le->vct_index_backup = le->vct_index;
		tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		if (*buff == '1')
			tputs(le->termcap[CLEAR_ALL_AFTER_CURS], 1, ms_putchar);
		else if (*buff == '2')
			tputs(tparm(tgetstr("DL", NULL), le->srows), le->srows, ms_putchar);
		else if (*buff == '5')
			tputs(le->termcap[ONE_ROW_DOWN], 1, ms_putchar);
		else if (*buff == '8')
			tputs(le->termcap[ONE_ROW_UP], 1, ms_putchar);
		else if (*buff == K_ENTER)
		{
			unselect_all(command_line);
			move_cursor_at_index(command_line, vct_getlen(command_line));
			tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
			return ;
		}
		else if (ft_isprint(*buff) == FALSE)
			handle_esc_seq(*(long *)buff, command_line);
		else if (ft_isprint(*buff) == TRUE)
			handle_print_char(buff[0], command_line);
		ft_bzero(buff, L_ED_BUFF_SIZE);
		if (DEBUG == TRUE)
			debug_print_infos(command_line);
		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
}
