#include "line_editor_bonus.h"

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

# define	NORMAL_EXIT					0
# define	ERR_ENV			 			-2
# define	ERR_NEW_VCT		 			-3
# define	ERR_VCT			 			-4
# define	ERR_ENVP		 			-5
# define	ERR_SCREEN_SIZE	 			-6
# define	ERR_TERM_NAME	 			-7
# define	ERR_TERMCAP		 			-8
# define	ERR_MALLOC		 			-9
# define	ERR_FORK		 			-10
# define	ERR_HUP			 			-11
# define	ERR_MS_PUTCHAR	 			-12
# define	ERR_MS_TPUTS 				-13

# define	NB_ERR_CODES				12

static void	print_exit_error(int error)
{
	static const int	err_code[NB_ERR_CODES] = {
		NORMAL_EXIT ,ERR_ENV ,ERR_NEW_VCT, ERR_VCT, ERR_ENVP, ERR_SCREEN_SIZE,
		ERR_TERM_NAME, ERR_TERMCAP, ERR_MALLOC, ERR_FORK, ERR_HUP,
		ERR_MS_PUTCHAR,ERR_MS_TPUTS };
	static const char	*err_code_str[NB_ERR_CODES] = {
		"Could not load environement variables.", "Could not malloc vector.",
		"Vector function failed.", "Envp is null.", "Screen size is too small.",
		"TERM environment variable not set.",
		"Minishell is not (yet) compatible to this Terminal",
		"Malloc could not allocate memory.", "Could not fork a child process.",
		"Received a Hang Up signal.", "Could not write on stdout",
		"Could not output termcaps" };
	int					i;

	i = 0;
	while (i < NB_ERR_CODES)
	{
		if (err_code[i] == error)
			ft_dprintf(STDERR_FILENO, "Minishell: %s\n", err_code_str[i]);
		i++;
	}
	return (NOT_FOUND);
}


static void		exit_routine_le(void)
{
	t_le		*le;

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
}

static void		exit_routine_env(void)
{
	t_list		*env_lst;

	env_lst = get_env_list(GET);
	if (env_lst != NULL)
		free_env_list(env_lst);
}

void		exit_routine(int err_code)
{
	int			last_exit_status;

	last_exit_status = get_env_value_int(get_env_list(GET), S_QUESTION_MARK);
	exit_routine_le();
	exit_routine_env();
	exit_routine_lexer();
	// ...

	if (err_code != NORMAL_EXIT)
	{
		print_exit_error(err_code);
		exit (err_code);
	}
	else
		ft_dprintf(STDERR_FILENO, "exit\n");
	exit(last_exit_status);
}


