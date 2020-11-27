#include "minishell_bonus.h"

void	print_prompt(void)
{
	char	*prompt_str;

	if (DEBUG_MODE == TRUE)
		prompt_str = PROMPT_SIMPLE;
	else
		prompt_str = PROMPT_LINE_EDITION;
	// if (isatty(STDOUT_FILENO) == TRUE)						// TODO: NO BONUS REMOVE FORBIDDEN !!
	// 	ft_putstr_fd(prompt_str, STDOUT_FILENO);
	// else if (isatty(STDERR_FILENO) == TRUE)
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

void	init_prompt(void)
{
	t_le	*le;

	le = get_struct(GET);
	print_prompt();
	if (DEBUG_MODE != TRUE)
	{
		le = get_struct(GET);
		if (le->prompt_len >= le->scols)
			exit_routine(EXIT_SCREEN_SIZE);
		le->cx = (int)le->prompt_len;
		le->cy = 0;
		le->vct_index = 0;
	}
	clear_command_line();
}
