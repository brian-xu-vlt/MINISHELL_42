#include "line_editor_bonus.h"

void		line_editor(t_vector *command_line)
{
	char	buff;
	int		ret;
	t_le	*le;

	if (command_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	le = get_env(GET);
	update_window_size();
	init_prompt();
	init_selection();
	buff = '\0';
	ret = CONTINUE;
	while(ret == CONTINUE && read(STDIN_FILENO, &buff, 1) >= 0)
	{
		le->vct_index_backup = le->vct_index;
		tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		if (buff == '1')
			move_previous_line_startingpoint();
		else if (buff == '2')
			print(command_line);
		else if (buff == '3')
		{
			ft_putstr_fd("........................", STDERR_FILENO);
	//		tputs(tgetstr(("cr"), NULL), 1, ms_putchar);
	//		tputs(le->termcap[ONE_ROW_DOWN], 1, ms_putchar);
		}
		else if (buff == K_ENTER)
			break ;
		else if (ft_isprint(buff) == TRUE)
			handle_print_char(buff, command_line);
		else
			ret = handle_esc_seq(buff, command_line);
		buff = '\0';
		if (DEBUG == TRUE)
			debug_print_infos(command_line);
		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	unselect_all(command_line);
	move_cursor_at_index(command_line, vct_getlen(command_line));
}
