#include "line_editor_bonus.h"

static void	debug_cursor_newline(void)
{
	t_le	*le;

	le = get_struct(GET);
	ms_tputs(tparm(le->termcap[MOVE_AT_COL_X], 0), 2, ms_putchar);
	ms_tputs(le->termcap[ONE_ROW_DOWN], 2, ms_putchar);
	ms_tputs(le->termcap[CLEAR_LINE], 2, ms_putchar);
}

void		debug_print_infos(void)
{
	t_le	*le;

	le = get_struct(GET);
	ms_tputs(tgetstr(SAVE_CURSOR_POS, NULL), 2, ms_putchar);
	ms_tputs(le->termcap[MOVE_CURSOR_HOME], le->cy, ms_putchar);
	ms_tputs(tgetstr(HIGHLIGHT, NULL), 1, ms_putchar);
	ms_tputs(le->termcap[CLEAR_LINE], 2, ms_putchar);
	ft_printf("cursor col [%d/%d] ", le->cx, le->scols);
	ft_printf("line [%d] vct_index [%d] ", le->cy, le->vct_index);
	ft_printf("vct_len[%d] char_in_vct [%c]", vct_getlen(le->cmd_line),
									vct_getcharat(le->cmd_line, le->vct_index));
	debug_cursor_newline();
	ft_printf("select_min/max [%d/%d] vct_content : \n___%s\n", le->select_min,
		le->select_max, vct_getstr(le->cmd_line));
	debug_cursor_newline();
	ms_tputs(le->termcap[CLEAR_LINE], 2, ms_putchar);
	ft_printf("Clipboard [%s]", vct_getstr(le->clipboard));
	ms_tputs(tgetstr(NO_HIGHLIGHT, NULL), 1, ms_putchar);
	ms_tputs(tgetstr(RESTORE_CURSOR_POS, NULL), 2, ms_putchar);
}

void		debug_print_flag(char *flag)
{
	t_le	*le;

	le = get_struct(GET);
	ms_tputs(tgetstr(SAVE_CURSOR_POS, NULL), 2, ms_putchar);
	ms_tputs(tparm(le->termcap[MOVE_X_ROWS_UP], 6), 2, ms_putchar);
	ms_tputs(tparm(le->termcap[MOVE_AT_COL_X], 0), 2, ms_putchar);
	ms_tputs(tgetstr(HIGHLIGHT, NULL), 1, ms_putchar);
	ms_tputs(le->termcap[CLEAR_LINE], 2, ms_putchar);
	ft_putstr_fd("debug ", STDERR_FILENO);
	ft_putstr_fd(flag, STDERR_FILENO);
	ms_tputs(tgetstr(NO_HIGHLIGHT, NULL), 1, ms_putchar);
	ms_tputs(tgetstr(RESTORE_CURSOR_POS, NULL), 2, ms_putchar);
}
