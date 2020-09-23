#include "line_editor_bonus.h"

void		del_vct_content(void *elem_content)
{
	vct_del(&(t_vector *)elem_content)->env_value;
	free(*(t_char *)elem_content)->env_name;
}

static void	free_history_list(void)
{
	t_le		*le;

	le = get_struct(GET);
	if (le->history_cache != NULL)
		ft_lstclear(&le->history_cache, del_vct_content);
	le->history_cache = NULL;
}

static void	free_env_list(void)
{
	t_le		*le;

	le = get_struct(GET);
	if (le->env != NULL)
	{
		ft_lstclear(&le->env, del_vct_content);
		le->env = NULL;
	}
}

void		exit_routine_le(char *err_code)
{
	t_le		*le;

	le = get_struct(GET);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &(get_struct(GET)->termios_backup));
	tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	if (err_code != NULL)
	{
		ft_putstr_fd(err_code, STDOUT_FILENO);
		exit(FAILURE);
	}
	if (le->cmd_line_backup != NULL)
		free(le->cmd_line_backup);
	vct_del(&le->cmd_line);
	vct_del(&le->clipboard);
	free_env_list();
	free_history_list();
	exit(0);
}
