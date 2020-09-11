#include "line_editor_bonus.h"

static void	debug_cursor_newline(void)
{
	char 	*buff;

	buff = tparm(tgetstr("ch", NULL), 0); //set param termcap for col argument at 0
	tputs(buff, 2, ms_putchar); // cursor @ col 0 of same line
	tputs(tgetstr("do", NULL), 2, ms_putchar); // cursor 1 row down
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
}

void	debug_print_infos(t_vector *command_line)
{
	size_t	vct_index;
	t_le	*le;

	le = get_env(GET);
	vct_index = convert_cur_pos_vctindex(le->cx, le->cy);
	tputs(tgetstr("sc", NULL), 2, ms_putchar); // save location
	tputs(tgetstr("ho", NULL), 2, ms_putchar); // go home 0,0
	tputs(tgetstr("md", NULL), 2, ms_putchar); // double bright
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
	ft_printf("cursor col [%d/%d] line [%d] vct_index [%d] vct_len[%d] char_in_vct [%c]",
		le->cx, le->scols, le->cy, le->vct_index,
		vct_getlen(command_line),vct_getcharat(command_line, vct_index));
	debug_cursor_newline();
	ft_printf("select_min/max [%d/%d]vct_content [%s]", le->select_min,
		le->select_max, vct_getstr(command_line));
	debug_cursor_newline();
	ft_printf("Clipboard [%s]", vct_getstr(le->clipboard));
	tputs(tgetstr("me", NULL), 2, ms_putchar); // restore appearance
	tputs(tgetstr("rc", NULL), 2, ms_putchar); // restore location
}

void	debug_print_flag(char *flag)
{
	tputs(tgetstr("sc", NULL), 2, ms_putchar); // save location
	tputs(tgetstr("up", NULL), 2, ms_putchar); // go up 1 line
	tputs(tgetstr("md", NULL), 2, ms_putchar); // double bright
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
	ft_putstr_fd(flag, STDERR_FILENO);
	tputs(tgetstr("me", NULL), 2, ms_putchar); // restore appearance
	tputs(tgetstr("rc", NULL), 2, ms_putchar); // restore location
}
