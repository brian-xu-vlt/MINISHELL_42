#include "line_editor_bonus.h"

static void		del_history_elem(void *elem_content)
{
	t_vector	*vct;

	vct = (t_vector *)elem_content;
	vct_del(&vct);
}

static void	free_history_list(void)
{
	t_le		*le;

	le = get_struct(GET);
	if (le->history_cache != NULL)
		ft_lstclear(&le->history_cache, del_history_elem);
	le->history_cache = NULL;
}

static void	free_env_list(void)
{
	t_env_data		*env_data;

	env_data = get_env_data(GET);
	if (env_data->env_lst != NULL)
	{
		ft_lstclear(&env_data->env_lst, del_env_elem);
		env_data->env_lst = NULL;
	}
}

void		exit_routine_le(char *err_code)
{
	t_le		*le;

	le = get_struct(GET);
	if (le->termios_backup != NULL)
		tcsetattr(STDIN_FILENO, TCSADRAIN, le->termios_backup);
	if (le->termcap[VISIBLE_CURSOR] != NULL)
		tputs(le->termcap[VISIBLE_CURSOR], 1, ms_putchar);
	if (le->cmd_line_backup != NULL)
		free(le->cmd_line_backup);
	vct_del(&le->cmd_line);
	vct_del(&le->clipboard);
	free_env_list();
	free_history_list();
	if (err_code != NULL)
	{
		ft_printf("%s\n", err_code);
		exit(FAILURE);
	}
	exit(0);
}
