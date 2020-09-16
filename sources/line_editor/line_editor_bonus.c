#include "line_editor_bonus.h"

void		line_editor(void)
{
	char	buff;
	int		ret;
	t_le	*le;

	le = get_env(GET);
	if (le->cmd_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	update_window_size();
	init_prompt();
	init_selection();
	buff = '\0';
	ret = CONTINUE;
	while(ret == CONTINUE && read(STDIN_FILENO, &buff, 1) >= 0)
	{
		le->vct_index_backup = le->vct_index;
//		tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		if (buff == K_ENTER)
			break ;
		else if (ft_isprint(buff) == TRUE)
			handle_print_char(buff);
		else
			ret = handle_esc_seq(buff);
		buff = '\0';
		if (DEBUG == TRUE)
			debug_print_infos();
//		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
//	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	unselect_all();
//	move_cursor_at_index(vct_getlen(le->cmd_line));
}
