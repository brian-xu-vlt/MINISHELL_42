#include "line_editor_bonus.h"

void	debug_print_infos(t_vector *command_line)
{
	char 	*buff;
	size_t	vct_index;

	vct_index = convert_cur_pos_vctindex(g_le.cx, g_le.cy);
	tputs(tgetstr("sc", NULL), 2, ms_putchar); // save location
	tputs(tgetstr("ho", NULL), 2, ms_putchar); // go home 0,0
	tputs(tgetstr("md", NULL), 2, ms_putchar); // double bright
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line

	ft_printf("cursor col [%d/%d] line [%d] vct_index [%d] char_in_vct [%c]", g_le.cx, g_le.scols, g_le.cy, convert_cur_pos_vctindex(g_le.cx, g_le.cy), vct_getcharat(command_line, vct_index));
	buff = tparm(tgetstr("ch", NULL), 0); //set param termcap for col argument at 0
	tputs(buff, 2, ms_putchar); // cursor @ col 0 of same line
	tputs(tgetstr("do", NULL), 2, ms_putchar); // cursor 1 row down
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
	ft_printf("select_min/max [%d/%d]\nvct_content [%s]", g_le.select_min, g_le.select_max, vct_getstr(command_line));
	tputs(tgetstr("me", NULL), 2, ms_putchar); // restore appearance
	tputs(tgetstr("rc", NULL), 2, ms_putchar); // restore location
}

void	debug_print_flag(char *flag)
{
	tputs(tgetstr("sc", NULL), 2, ms_putchar); // save location
	tputs(tgetstr("ho", NULL), 2, ms_putchar); // go home 0,0
	tputs(tgetstr("do", NULL), 2, ms_putchar); // go down 1 line
	tputs(tgetstr("do", NULL), 2, ms_putchar); // go down 1 line
	tputs(tgetstr("do", NULL), 2, ms_putchar); // go down 1 line
	tputs(tgetstr("md", NULL), 2, ms_putchar); // double bright
	tputs(tgetstr("ce", NULL), 2, ms_putchar); // clear current line
	ft_putstr_fd(flag, STDERR_FILENO);
	tputs(tgetstr("me", NULL), 2, ms_putchar); // restore appearance
	tputs(tgetstr("rc", NULL), 2, ms_putchar); // restore location
}
