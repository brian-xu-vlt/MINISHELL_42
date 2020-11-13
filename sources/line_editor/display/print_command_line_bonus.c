#include "line_editor_bonus.h"

static void		put_newline(t_le *le)
{
	ms_tputs(le->termcap[ONE_ROW_DOWN], 2, ms_putchar);
	ms_tputs(le->termcap[RETURN_CARRIAGE], 2, ms_putchar);
}

static ssize_t	secure_write(int fd, const void *buf, size_t nbyte)
{
	ssize_t		ret;

	errno = 0;
	ret = write(fd, buf, nbyte);
	if (ret == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine_le(ERR_NO_MESSAGE);
	}
	return (ret);
}

static void		write_with_selection(t_le *le, int index_from)
{
	int			vct_len;
	char		*v_str;
	const int	fd = STDOUT_FILENO;

	v_str = vct_getstr(le->cmd_line);
	vct_len = vct_getlen(le->cmd_line);
	if (le->select_min < index_from)
	{
		ms_tputs(le->termcap[SELECT], 1, ms_putchar);
		secure_write(fd, v_str + index_from, le->select_max - index_from + 1);
		ms_tputs(le->termcap[UNSELECT], 1, ms_putchar);
		secure_write(fd, v_str + le->select_max + 1, vct_len - le->select_max);
	}
	else
	{
		secure_write(fd, v_str + index_from, le->select_min - index_from);
		ms_tputs(le->termcap[SELECT], 1, ms_putchar);
		secure_write(fd, v_str + le->select_min, le->select_max - le->select_min + 1);
		ms_tputs(le->termcap[UNSELECT], 1, ms_putchar);
		secure_write(fd, v_str + le->select_max + 1, vct_len - le->select_max);
	}
}

void			print_cmd_line(void)
{
	int			index_from;
	int			i_delta;
	int			offset;
	t_le		*le;

	le = get_struct(GET);
	index_from = le->vct_index;
	i_delta = vct_getlen(le->cmd_line) - index_from;
	if (le->select_min == UNSET)
		secure_write(STDOUT_FILENO, vct_getstr(le->cmd_line) + index_from, i_delta);
	else
		write_with_selection(le, index_from);
	offset = (le->cy == 0) ? le->prompt_len : 0;
	if ((i_delta + offset) % le->scols == 0)
		put_newline(le);
}
