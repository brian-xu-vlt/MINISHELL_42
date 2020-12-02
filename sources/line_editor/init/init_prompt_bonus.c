#include "minishell_bonus.h"

void		print_prompt(void)
{
	char	*prompt_str;

	if (DEBUG_MODE == TRUE)
		prompt_str = PROMPT_SIMPLE;
	else
		prompt_str = PROMPT_LINE_EDITION;
	if (isatty(STDOUT_FILENO) == TRUE)						// TODO: NO BONUS REMOVE FORBIDDEN !!
		ft_putstr_fd(prompt_str, STDOUT_FILENO);
	else if (isatty(STDERR_FILENO) == TRUE)
		ft_putstr_fd(prompt_str, STDERR_FILENO);
}

static void	clear_command_line(void)
{
	t_data	*data;

	data = get_data_struct(GET);
	if (data == NULL)
		exit_routine(EXIT_MALLOC);
	else
		vct_clear(data->cmd_line);
}

static void	parse_buff(char *buff, int *x, int *y)
{
	char	**data;

	*x = UNSET;
	*y = UNSET;
	data = ft_split(buff, ';');
	if (data != NULL && data[0] != NULL && data[1] != NULL)
	{
		*x = ft_atoi(data[0]);
		*y = ft_atoi(data[1]);
	}
	free_char_arr(data);
}

static void	init_cursor(t_le *le)
{
	int		x;
	int		y;
	char	buff[64];
	int		ret;

	ft_bzero(buff, 64);
	if (le->termcap[CURSOR_POSITION_REQUEST] != NULL)
	{
		ms_tputs(le->termcap[CURSOR_POSITION_REQUEST], 1, ms_putchar);
		ret = read(STDIN_FILENO, buff, 64);
		parse_buff(buff, &x, &y);
		if (ret != FAILURE && y > 1)
		{
			tputs(le->termcap[SELECT], 1, ms_putchar);
			ft_putchar_fd('%', STDOUT_FILENO);
			tputs(le->termcap[UNSELECT], 1, ms_putchar);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		else if (y == UNSET)
			ft_putchar_fd('\r', STDOUT_FILENO);
	}
}

void		init_prompt(void)
{
	t_le	*le;

	le = get_struct(GET);
	if (le != NULL)
		init_cursor(le);
	print_prompt();
	if (le != NULL)
	{
		if (le->prompt_len >= le->scols)
			exit_routine(EXIT_SCREEN_SIZE);
		le->cx = (int)le->prompt_len;
		le->cy = 0;
		le->vct_index = 0;
	}
	clear_command_line();
}
