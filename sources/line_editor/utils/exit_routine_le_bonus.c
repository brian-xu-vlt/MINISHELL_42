#include "line_editor_bonus.h"

void	del_history(void *elem_content)
{
	t_vector	*vct;

	vct = (t_vector *)elem_content;
	vct_del(&vct);
}

void	free_history(void)
{
	t_le		*le;

	le = get_env(GET);
	if (le->history_cache != NULL)
		ft_lstclear(&le->history_cache, del_history);
	le->history_cache = NULL;
}

void	exit_routine_le(char *err_code)
{
	t_le		*le;

	le = get_env(GET);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(get_env(GET)->termios_backup));
	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	if (err_code != NULL)
	{
		ft_putstr_fd(err_code, STDOUT_FILENO);
		exit(FAILURE);
	}
	if (le->cmd_line != NULL)
		vct_del(&le->cmd_line);
	if (le->clipboard != NULL)
		vct_del(&le->clipboard);
	if (le->cmd_line_backup != NULL)
		free(le->cmd_line_backup);
	free_history();
	exit(0);
}
