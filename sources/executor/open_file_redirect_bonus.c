#include "minishell_bonus.h"

static int	process_less(char *str, t_cmd *cmd)
{
	int				fd;
	static size_t	i = 0;

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

static int	process_greater(char *str, t_cmd *cmd)
{
	int				fd;
	static size_t	i = 0;

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

static int	process_double_greater(char *str, t_cmd *cmd)
{
	int				fd;
	static size_t	i = 0;

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

static void	init_cmd_redirection(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		if (cmd->fd[0] != STDIN_FILENO && cmd->fd[0] == cmd->tmp_fd_in)
			cmd->redirection = cmd->redirection | F_REDIRECT_IN;
		if (cmd->fd[1] != STDOUT_FILENO && cmd->fd[1] == cmd->tmp_fd_out)
			cmd->redirection = cmd->redirection | F_REDIRECT_OUT;
		if (cmd->fd[1] != STDOUT_FILENO && cmd->fd[1] == cmd->tmp_fd_append)
			cmd->redirection = cmd->redirection | F_REDIRECT_OUT
												| F_REDIRECT_OUT_APPEND;
	}
}

void		process_open_file(t_cmd *cmd, int flag)
{
	size_t			i;
	int				ret_file;
	size_t			size;

	i = 0;
	size = 0;
	ret_file = SUCCESS;
	size = set_size(cmd, flag);
	while (i < size)
	{
		if (ft_strequ(flag == AFTER ? cmd->tab_redir[i] :
				cmd->tab_redir_before[i], DOUBLE_GREATER) == TRUE)
			ret_file = process_double_greater(flag == AFTER ?
				cmd->tab_redir[i + 1] : cmd->tab_redir_before[i + 1], cmd);
		else if (ft_strequ(flag == AFTER ? cmd->tab_redir[i] :
				cmd->tab_redir_before[i], GREATER_THAN) == TRUE)
			ret_file = process_greater(flag == AFTER ?
				cmd->tab_redir[i + 1] : cmd->tab_redir_before[i + 1], cmd);
		else if (ft_strequ(flag == AFTER ? cmd->tab_redir[i] :
				cmd->tab_redir_before[i], LESS_THAN) == TRUE)
			ret_file = process_less(flag == AFTER ? cmd->tab_redir[i + 1] :
				cmd->tab_redir_before[i + 1], cmd);
		if (ret_file == FAILURE || ret_file == NO_FILE)
		{
			if (ret_file == NO_FILE)
				print_file_error(flag == AFTER ? cmd->tab_redir :
					cmd->tab_redir_before, i, cmd->count_redir);
			cmd->redirection = cmd->redirection | F_REDIRECT_FAILURE;
			return ;
		}
		i += 2;
		if (i >= size)
			break ;
	}
	init_cmd_redirection(cmd);
}
