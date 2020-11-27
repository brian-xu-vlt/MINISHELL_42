#include "minishell_bonus.h"

void	dup_pipes(t_cmd *command, int p_in[2], int p_out[2])
{
	if (p_in[R_END] != UNSET)
	{
		ms_dup2(p_in[R_END], STDIN_FILENO);
		close_pipe_end(p_in[W_END]);
	}
	if (p_out[W_END] != UNSET)
	{
		ms_dup2(p_out[W_END], command->fd[STDOUT_FILENO]);
		close_pipe_end(p_out[R_END]);
	}
}

void	close_pipe_end(int pipe_to_close)
{
	int		close_ret;

	close_ret = 0;
	if (pipe_to_close != UNSET)
	{
		close_ret = close(pipe_to_close);
		// if (DEBUG_MODE == TRUE && close_ret == FAILURE)
			// print_set_errno(errno, NULL, "close pipe: ", NULL);
		pipe_to_close = UNSET;
	}
}

int		ms_pipe(int pipe_fd[2])
{
	int		ret;

	ret = pipe(pipe_fd);
	if (ret == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_NORMAL);
	}
	return (ret);
}

int		ms_dup2(int old_fd, int new_fd)
{
	int		ret;

	errno = 0;
	ret = dup2(old_fd, new_fd);
	if (ret == FAILURE || ret != new_fd)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_NORMAL);
	}
	return (ret);
}

int		ms_dup(int old_fd)
{
	int		ret;

	errno = 0;
	ret = dup(old_fd);
	if (ret == FAILURE)
	{
		print_set_errno(errno, NULL, NULL, NULL);
		exit_routine(EXIT_NORMAL);
	}
	return (ret);
}
