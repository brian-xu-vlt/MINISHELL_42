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
	return (write(STDOUT_FILENO, &c, 1));
}

static void	exit_routine_reset_terminal(t_le *le)
{
	if (le->termcap[VISIBLE_CURSOR] != NULL)
		tputs(le->termcap[VISIBLE_CURSOR], 1, ft_putchar);
	if (le->termios_bkup != NULL)
		tcsetattr(STDIN_FILENO, TCSADRAIN, le->termios_bkup);
}

void		exit_routine_le(char *err_code)
{
	t_le		*le;
	t_list		*env_lst;
	int			last_exit_status;

	le = get_struct(GET);
	if (le != NULL)
	{
		exit_routine_reset_terminal(le);
		if (le->cmd_line_backup != NULL)
			free(le->cmd_line_backup);
		vct_del(&le->cmd_line);
		vct_del(&le->clipboard);
		free_history_list(le);
	}
	env_lst = get_env_list(GET);
	if (env_lst != NULL)
	{
		last_exit_status = get_env_value_int(env_lst, S_QUESTION_MARK);
		free_env_list(env_lst);
	}
	if (ft_strequ(err_code, NORMAL_EXIT) == FALSE)
	{
		if (ft_strequ(err_code, EXIT_MALLOC) == TRUE)
			errno = ENOMEM;
		if (err_code != ERR_NO_MESSAGE)
		{
			ft_putstr_fd(err_code, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			exit(FAILURE);
		}
	}
	// ft_printf("%s\n", NORMAL_EXIT);
	exit(last_exit_status);
}
