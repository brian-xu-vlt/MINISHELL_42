/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:49:49 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:49:50 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		read_loop(void)
{
	int			read_ret;
	t_data		*data;

	read_ret = 0;
	data = get_data_struct(GET);
	if (data == NULL)
		exit_routine(EXIT_MALLOC);
	init_prompt();
	errno = 0;
	if ((read_ret = vct_readline(data->cmd_line, 0)) == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_ERRNO);
	}
	return (read_ret);
}

static t_list	*process_minishell(t_vector *cmd_line)
{
	t_list		*lexer_list;
	t_list		*jobs;
	int			ret_parser;

	lexer_list = NULL;
	jobs = NULL;
	ret_parser = SUCCESS;
	lexer_list = test_lexer(cmd_line);
	if (lexer_list != NULL)
	{
		ret_parser = test_parser(lexer_list);
		if (ret_parser != FALSE)
			jobs = test_jobs(lexer_list);
		if (jobs == NULL)
			free_list_job(&jobs);
	}
	free_list_token(&lexer_list);
	return (jobs);
}

static int		reader(void)
{
	int			ret_read;

	ret_read = 0;
	if (DEBUG_MODE != TRUE)
	{
		signal_manager(SIG_MODE_CMD_LINE);
		ret_read = line_editor();
	}
	else
	{
		signal_manager(SIG_MODE_CMD_LINE_NO_BONUS);
		ret_read = read_loop();
	}
	return (ret_read);
}

static int		minishell_loop(t_vector *cmd_line, t_data *data)
{
	int			ret_read;
	t_list		*jobs;

	ret_read = reader();
	jobs = NULL;
	if (vct_getlen(cmd_line) > 0)
	{
		jobs = process_minishell(cmd_line);
		if (jobs != NULL)
		{
			data->current_jobs = jobs;
			if (hub_cleaner(jobs) == FAILURE)
				exit_routine(EXIT_MALLOC);
			free_list_job(&jobs);
			data->current_jobs = NULL;
			vct_clear(cmd_line);
		}
	}
	return (ret_read);
}

int				main(int ac, char **av)
{
	t_vector	*cmd_line;
	t_data		*data;
	int			ret_read;

	check_std_fd();
	usage(ac, av);
	data = init_data_struct();
	cmd_line = safe_vct_new();
	data->cmd_line = cmd_line;
	init_env();
	if (DEBUG_MODE == FALSE)
		data->line_editor_data = init_line_editor(cmd_line);
	ret_read = 1;
	while (ret_read > 0)
		ret_read = minishell_loop(cmd_line, data);
	if (DEBUG_MODE == FALSE)
		ft_dprintf(STDERR_FILENO, "%s\n", EXIT);
	return (exit_main());
}
