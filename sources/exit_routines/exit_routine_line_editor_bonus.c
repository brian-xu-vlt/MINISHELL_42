#include "minishell_bonus.h"

static void	del_history_elem(void *elem_content)
{
	t_vector	*vct;

	vct = (t_vector *)elem_content;
	if (vct != NULL)
		vct_del(&vct);
}

static void	free_history_list(t_le *le)
{
	if (le->history_cache != NULL)
		ft_lstclear(&le->history_cache, del_history_elem);
	le->history_cache = NULL;
}

static int	ft_putchar(int c)
{
	return (write(STDERR_FILENO, &c, 1));
}

static void	exit_routine_reset_terminal(t_le *le)
{
	tputs(le->termcap[VISIBLE_CURSOR], 1, ft_putchar);
	if (le != NULL && le->termios_bkup != NULL)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, le->termios_bkup);
}

void		exit_routine_line_edition(t_le *le, int err_code)
{
	if (le != NULL)
	{
		if (err_code != EXIT_NORMAL)
			exit_routine_reset_terminal(le);
		if (le->cmd_line_backup != NULL)
			free(le->cmd_line_backup);
		vct_del(&le->clipboard);
		free_history_list(le);
	}
}
