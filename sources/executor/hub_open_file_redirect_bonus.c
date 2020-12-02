#include "minishell_bonus.h"

int process_less(char *str, t_cmd *cmd)
{
	int fd;
	static size_t i = 0;

	if (str == NULL || ft_strequ(LESS_THAN, str) == TRUE)
		return (NO_FILE);
	fd = open(str, O_RDONLY | O_EXCL, 0644);
	if (fd < 0)
	{
		if (cmd->tmp_fd_in > 2)
			close(cmd->tmp_fd_in);
		if (cmd->tmp_fd_out > 2)
			close(cmd->tmp_fd_out);
		print_set_errno(errno, strerror(errno), str, NULL);
		return (FAILURE);
	}
	if (cmd->tmp_fd_in > 2)
		close(cmd->tmp_fd_in);
	cmd->tmp_fd_in = fd;
	cmd->fd[STDIN_FILENO] = fd;
	i++;
	return (SUCCESS);
}

int process_greater(char *str, t_cmd *cmd)
{
	int fd;
	static size_t i = 0;

	if (str == NULL || ft_strequ(GREATER_THAN, str) == TRUE)
		return (NO_FILE);
	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
	{
		if (cmd->tmp_fd_in > 2)
			close(cmd->tmp_fd_in);
		if (cmd->tmp_fd_out > 2)
			close(cmd->tmp_fd_out);
		print_set_errno(errno, strerror(errno), str, NULL);
		return (FAILURE);
	}
	if (cmd->tmp_fd_out > 2)
		close(cmd->tmp_fd_out);
	cmd->tmp_fd_out = fd;
	cmd->fd[STDOUT_FILENO] = fd;
	i++;
	return (SUCCESS);
}

int process_double_greater(char *str, t_cmd *cmd)
{
	int fd;
	static size_t i = 0;

	if (str == NULL || ft_strequ(DOUBLE_GREATER, str) == TRUE)
		return (NO_FILE);
	fd = open(str, O_WRONLY | O_APPEND | O_CREAT, 0664);
	if (fd < 0)
	{
		if (cmd->tmp_fd_in > 2)
			close(cmd->tmp_fd_in);
		if (cmd->tmp_fd_out > 2)
			close(cmd->tmp_fd_out);
		print_set_errno(errno, strerror(errno), str, NULL);
		return (FAILURE);
	}
	if (cmd->tmp_fd_append > 2)
		close(cmd->tmp_fd_append);
	cmd->tmp_fd_append = fd;
	cmd->fd[STDOUT_FILENO] = fd;
	i++;
	return (SUCCESS);
}
