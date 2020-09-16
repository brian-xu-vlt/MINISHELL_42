#include "line_editor_bonus.h"

static void	debug_cursor_newline(void)
{
	char 	*buff;

	buff = tparm(tgetstr("ch", NULL), 0); //set param termcap for col argument at 0
	tputs(buff, 2, ms_putchar); // cursor @ col 0 of same line
	tputs(tgetstr("do", NULL), 2, ms_putchar); // cursor 1 row down
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
}

void	debug_print_infos(void)
{
	t_le	*le;

	le = get_env(GET);
	tputs(tgetstr("sc", NULL), 2, ms_putchar); // save location
	tputs(tgetstr("ho", NULL), 2, ms_putchar); // go home 0,0
	tputs(tgetstr("md", NULL), 2, ms_putchar); // double bright
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
	ft_printf("cursor col [%d/%d] line [%d] vct_index [%d] vct_len[%d] char_in_vct [%c]",
		le->cx, le->scols, le->cy, le->vct_index,
		vct_getlen(le->cmd_line),vct_getcharat(le->cmd_line, le->vct_index));
	debug_cursor_newline();
	ft_printf("select_min/max [%d/%d]vct_content : \n___%s\n", le->select_min,
		le->select_max, vct_getstr(le->cmd_line));
	debug_cursor_newline();
//	ft_printf("Clipboard [%s]", vct_getstr(le->clipboard));
	tputs(tgetstr("me", NULL), 2, ms_putchar); // restore appearance
	tputs(tgetstr("rc", NULL), 2, ms_putchar); // restore location
}

void	debug_print_flag(char *flag)
{
	char	*buff;

	tputs(tgetstr("sc", NULL), 2, ms_putchar); // save location
	buff = tparm(tgetstr("UP", NULL), 6); //set param termcap for col argument at 0
	tputs(buff, 6, ms_putchar); // cursor @ col 0 of same line
	buff = tparm(tgetstr("ch", NULL), 0); //set param termcap for col argument at 0
	tputs(buff, 2, ms_putchar); // cursor @ col 0 of same line
	tputs(tgetstr("md", NULL), 2, ms_putchar); // double bright
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
	ft_putstr_fd("debug ", STDOUT_FILENO);
	ft_putstr_fd(flag, STDOUT_FILENO);
	tputs(tgetstr("me", NULL), 2, ms_putchar); // restore appearance
	tputs(tgetstr("rc", NULL), 2, ms_putchar); // restore location
}
