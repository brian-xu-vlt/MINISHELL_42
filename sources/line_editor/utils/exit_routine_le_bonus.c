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

void		del_env_elem(void *elem_content)
{
	char		*env_name;
	t_vector	*env_value;

	env_value = ((t_env *)elem_content)->env_value;
	if (env_value != NULL)
		vct_del(&env_value);
	env_name = ((t_env *)elem_content)->env_name;
	free(env_name);
	free(elem_content);
}

static void	free_env_list(void)
{
	t_le		*le;

	le = get_struct(GET);
	if (le->env != NULL)
	{
		ft_lstclear(&le->env, del_env_elem);
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
//	exit(0);
}
