#include "minishell_bonus.h"

static int process_less(char *str, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	int fd;
	static size_t i = 0;

	fd = open(str, O_RDONLY | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	//clean_cmd->tab_fd_in[i] = fd;
	if (fd < 0)
	{
		if (clean_cmd->tmp_fd_in > 2)
			close(clean_cmd->tmp_fd_in);
		if (clean_cmd->tmp_fd_out > 2)
			close(clean_cmd->tmp_fd_out);
		print_set_errno(errno, "bash", str);
		return (FAILURE);
	}
	if (clean_cmd->tmp_fd_in > 2)
		close(clean_cmd->tmp_fd_in);
	clean_cmd->tmp_fd_in = fd;
	cmd->fd[STDIN_FILENO] = fd;
	i++;
	return (SUCCESS);
}

static int process_greater(char *str, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	int fd;
	static size_t i = 0;

	fd = open(str, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	//clean_cmd->tab_fd_out[i] = fd;
	if (fd < 0)
	{
		if (clean_cmd->tmp_fd_in > 2)
			close(clean_cmd->tmp_fd_in);
		if (clean_cmd->tmp_fd_out > 2)
			close(clean_cmd->tmp_fd_out);
		print_set_errno(errno, "bash", str);
		return (FAILURE);
	}
	if (clean_cmd->tmp_fd_out > 2)
		close(clean_cmd->tmp_fd_out);
	clean_cmd->tmp_fd_out = fd;
	cmd->fd[STDOUT_FILENO] = fd;
	i++;
	return (SUCCESS);
}

static int process_double_greater(char *str, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	int fd;
	static size_t i = 0;

	fd = open(str, O_RDONLY | O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	//clean_cmd->tab_fd_out_append[i] = fd;
	if (fd < 0)
	{
		if (clean_cmd->tmp_fd_in > 2)
			close(clean_cmd->tmp_fd_in);
		if (clean_cmd->tmp_fd_out > 2)
			close(clean_cmd->tmp_fd_out);
		print_set_errno(errno, "bash", str);
		return (FAILURE);
	}
	if (clean_cmd->tmp_fd_append > 2)
		close(clean_cmd->tmp_fd_append);
	clean_cmd->tmp_fd_append = fd;
	cmd->fd[STDOUT_FILENO] = fd;
	i++;
	return (SUCCESS);
}

static int process_open_file(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t i;
	int ret_file;

	i = 0;
	ret_file = SUCCESS;
	while (i < clean_cmd->count_redir)
	{
		if (ft_strequ(clean_cmd->tab_redir[i], DOUBLE_GREATER) == TRUE)
			ret_file = process_double_greater(clean_cmd->tab_redir[i + 1], cmd,
											  clean_cmd);
		else if (ft_strequ(clean_cmd->tab_redir[i], GREATER_THAN) == TRUE)
			ret_file = process_greater(clean_cmd->tab_redir[i + 1], cmd,
									   clean_cmd);
		else if (ft_strequ(clean_cmd->tab_redir[i], LESS_THAN) == TRUE)
			ret_file = process_less(clean_cmd->tab_redir[i + 1], cmd, clean_cmd);
		if (ret_file == FAILURE)
			return (FAILURE);
		i += 2;
		if (i >= clean_cmd->count_redir)
			break;
	}
	return (SUCCESS);
}

int process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	cmd->redirection = 0;
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (process_open_file(cmd, clean_cmd) == FAILURE)
		return (FILE_FAIL);
	ft_printf("\033[0;32mDEBUG FD FINAL\n\033[0m"); //DEBUG
	debug_fd(cmd->fd);
	if (cmd->fd[0] != STDIN_FILENO && cmd->fd[0] == clean_cmd->tmp_fd_in)
		cmd->redirection = cmd->redirection | F_REDIRECT_IN;
	if (cmd->fd[1] != STDOUT_FILENO && cmd->fd[1] == clean_cmd->tmp_fd_out)
		cmd->redirection = cmd->redirection | F_REDIRECT_OUT;
	if (cmd->fd[1] != STDOUT_FILENO && cmd->fd[1] == clean_cmd->tmp_fd_append)
		cmd->redirection = cmd->redirection | F_REDIRECT_OUT | F_REDIRECT_OUT_APPEND;
	//ret_pwd = get_pwd(cmd->fd_string);
	//if (ret_pwd != SUCCESS)
		//return (ret_pwd);
	ft_printf("\033[0;32mDEBUG FD_STRING FINAL\n\033[0m"); //DEBUG
	debug_fd_string(cmd->fd_string);
	return (SUCCESS);
}
