#include "line_editor_bonus.h"

void		line_editor(void)
{
	char	buff;
	t_le	*le;

	le = get_env(GET);
	if (le->cmd_line == NULL)
		exit_routine_le(ERR_NEW_VCT);
	update_window_size();
	init_prompt();
	init_selection();
	while(read(STDIN_FILENO, &buff, 1) != FAILURE && buff != K_ENTER)
	{
//		tputs(le->termcap[HIDE_CURSOR], 1, ms_putchar);
		le->vct_index_backup = le->vct_index;
		if (ft_isprint(buff) == TRUE)
			handle_print_char(buff);
		else
			handle_esc_seq(buff);
		if (DEBUG == TRUE)
			debug_print_infos();

//		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	}
	if (le->cmd_line_backup != NULL)
	{
		free(le->cmd_line_backup);
		le->cmd_line_backup = NULL;
	}
	unselect_all();
//	move_cursor_at_index(vct_getlen(le->cmd_line));
}
