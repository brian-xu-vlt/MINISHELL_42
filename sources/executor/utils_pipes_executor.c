/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes_executor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:17:49 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:17:50 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file(t_cmd *command, int fd_fileno)
{
	int					open_flags;
	int					fd_return;

	open_flags = 0;
	if (fd_fileno == STDIN_FILENO)
		open_flags = O_RDONLY;
	else
	{
		if (command->redirection & F_REDIRECT_OUT_APPEND)
			open_flags = O_WRONLY | O_CREAT | O_APPEND;
		else if (command->redirection & F_REDIRECT_OUT)
			open_flags = O_WRONLY | O_CREAT | O_TRUNC;
	}
	fd_return = open(command->fd_string[fd_fileno], open_flags, 0664);
	if (fd_return < 0)
		print_set_errno(errno, NULL, command->fd_string[fd_fileno], NULL);
	command->fd[fd_fileno] = fd_return;
	return (fd_return);
}

void		dup_pipes(const t_cmd *command, int p_in[2], int p_out[2])
{
	struct stat	statbuf;

	if (command->redirection & F_REDIRECT_IN)
		ms_dup2(open_file((t_cmd *)command, STDIN_FILENO), STDIN_FILENO);
	else if (p_in[R_END] != UNSET && fstat(p_in[R_END], &statbuf) != FAILURE)
	{
		ms_dup2(p_in[R_END], STDIN_FILENO);
		close_pipe_end(p_in[W_END]);
	}
	if (command->redirection & F_REDIRECT_OUT)
		ms_dup2(open_file((t_cmd *)command, STDOUT_FILENO), STDOUT_FILENO);
	else if (p_out[W_END] != UNSET && fstat(p_out[W_END], &statbuf) != FAILURE)
	{
		ms_dup2(p_out[W_END], command->fd[STDOUT_FILENO]);
		close_pipe_end(p_out[R_END]);
	}
}

void		close_pipe_end(int pipe_to_close)
{
	int		close_ret;

	close_ret = 0;
	if (pipe_to_close != UNSET)
	{
		close_ret = close(pipe_to_close);
		if (DEBUG_MODE == TRUE && close_ret == FAILURE)
			print_set_errno(errno, NULL, "close pipe: ", NULL);
		pipe_to_close = UNSET;
	}
}

void		do_pipe(int pipe_fd[2])
{
	int		pipe_ret;

	pipe_ret = pipe(pipe_fd);
	if (pipe_ret == FAILURE)
		print_set_errno(errno, NULL, "do pipe: ", NULL);
}
