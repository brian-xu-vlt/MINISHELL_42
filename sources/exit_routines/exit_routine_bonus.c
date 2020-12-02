/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routine_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:40:07 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:40:08 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	put_err(const char *err_code_str)
{
	if (write(STDERR_FILENO, "", 0) == FAILURE)
		ft_dprintf(STDOUT_FILENO, "Minishell: %s\n", err_code_str);
	else
		ft_dprintf(STDERR_FILENO, "Minishell: %s\n", err_code_str);
}

static void	print_exit_error(const int error)
{
	static const int	err_code[NB_EXIT_CODES] = {
EXIT_ENV, EXIT_NEW_VCT, EXIT_VCT, EXIT_ENVP, EXIT_SCREEN_SIZE,
EXIT_TERM_NAME, EXIT_TERMCAP, EXIT_TERMLIB, EXIT_MALLOC, EXIT_FORK, EXIT_HUP,
EXIT_MS_PUTCHAR, EXIT_MS_TPUTS, EXIT_NO_TTY, EXIT_ERRNO, EXIT_UNKNOWN};
	static const char	*err_code_str[NB_EXIT_CODES] = {
		"Could not load environement variables.", "Could not malloc vector.",
		"Vector function failed.", "Envp is null.", "Screen size is too small.",
		"TERM environment variable not set.",
		"Minishell is not (yet) compatible to this Terminal",
		"Could not retrieve terminal capabilities",
		"Malloc could not allocate memory.", "Could not fork a child process.",
		"Received a Hang Up signal.", "Could not write on stdout",
		"Could not output termcaps",
		"No tty. Only Minishell without line edition can be use without tty",
		"", "Minishell encountered and error." };
	int					i;

	i = 0;
	while (i < NB_EXIT_CODES)
	{
		if (err_code[i] == error && ft_strlen(err_code_str[i]) > 0)
			put_err(err_code_str[i]);
		i++;
	}
}

static int	absolute_err_code(int err_code)
{
	return (err_code * -1);
}

void		exit_routine(int err_code)
{
	int			last_exit_status;
	t_data		*data;

	last_exit_status = get_env_value_int(get_env_list(GET), S_QUESTION_MARK);
	data = get_data_struct(GET);
	if (data != NULL)
	{
		if (data->cmd_line != NULL)
			vct_del(&data->cmd_line);
		exit_routine_line_edition(data->line_editor_data, err_code);
		exit_routine_env();
		if (data->current_jobs != NULL)
			free_list_job(&data->current_jobs);
		free(data);
	}
	vct_readline(NULL, -42);
	if (err_code != EXIT_NORMAL)
	{
		print_exit_error(err_code);
		exit(absolute_err_code(err_code));
	}
	exit(last_exit_status);
}
