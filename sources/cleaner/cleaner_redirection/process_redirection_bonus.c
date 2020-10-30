#include "minishell_bonus.h"

static int	process_less(char *str, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	extern int	errno;
	int			fd;
	static size_t	i = 0;

	errno = SUCCESS;
	ft_printf("STR = %s\n");//DEBUG
	fd = open(str, O_RDONLY | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP |
				S_IROTH);
	clean_cmd->tab_fd_in[i] = fd;
	if (fd < 0)
	{
		ft_printf("ERROR OR NOT\n");//DEBUG
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

static int	process_greater(char *str, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	extern int	errno;
	int			fd;
	static size_t	i = 0;

	errno = SUCCESS;
	fd = open(str, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
				S_IRGRP | S_IROTH);
	clean_cmd->tab_fd_out[i] = fd;
	ft_printf("fd = %d\n", fd);//DEBUG	
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
	cmd->fd[STDOUT_FILENO] = fd;
	i++;
	return (SUCCESS);
}

static int	process_double_greater(char *str, t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	extern int	errno;
	int			fd;
	static size_t	i = 0;

	errno = SUCCESS;
	fd = open(str, O_RDONLY | O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR |
				S_IRGRP | S_IROTH);
	clean_cmd->tab_fd_out_append[i] = fd;
	ft_printf("fd = %d\n", fd);//DEBUG	
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
	cmd->fd[STDOUT_FILENO] = fd;
	i++;
	return (SUCCESS);
}

static int	process_open_file(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	size_t	i;
	int		ret_file;

	ft_printf("\n\ncount_redir = %d\n", clean_cmd->count_redir);//DEBUG
	i = 0;
	ret_file = SUCCESS;
	while (i < clean_cmd->count_redir)
	{
		ft_printf("i = %d\n", i);//DEBUG
		if (ft_strequ(clean_cmd->tab_redir[i], DOUBLE_GREATER) == TRUE)
			ret_file = process_double_greater(clean_cmd->tab_redir[i + 1], cmd,
												clean_cmd);
		else if (ft_strequ(clean_cmd->tab_redir[i], GREATER_THAN) == TRUE)
			ret_file = process_greater(clean_cmd->tab_redir[i + 1], cmd,
											clean_cmd);
		else if (ft_strequ(clean_cmd->tab_redir[i], LESS_THAN) == TRUE)
		{
			ft_printf("ENTER HER\n");//DEBUG
			ret_file = process_less(clean_cmd->tab_redir[i + 1], cmd, clean_cmd);
		}
		if (ret_file == FAILURE)
		{
			ft_printf("RET_FILE == FAILURE\n");
			return (FAILURE);
		}
		i += 2;
		if (i > clean_cmd->count_redir)
			break ;
	}
	return (SUCCESS);
}

static int	init_tab_fd(t_clean_cmd *clean_cmd)
{
	size_t	i;

	i = 0;
	ft_printf("count_redir = %d\n", clean_cmd->count_redir);//DEBUG
	clean_cmd->tab_fd_in = (int *)malloc(sizeof(int) *
							clean_cmd->count_redir);
	if (clean_cmd->tab_fd_in == NULL)
		return (FAILURE);//ERROR
	clean_cmd->tab_fd_out = (int *)malloc(sizeof(int) *
							clean_cmd->count_redir);
	if (clean_cmd->tab_fd_out == NULL)
		return (FAILURE);//ERROR
	clean_cmd->tab_fd_out_append = (int *)malloc(sizeof(int) *
							clean_cmd->count_redir);
	if (clean_cmd->tab_fd_out_append == NULL)
		return (FAILURE);//ERROR
	while (i < clean_cmd->count_redir)
	{
		clean_cmd->tab_fd_in[i] = STDIN_FILENO;
		clean_cmd->tab_fd_out[i] = STDOUT_FILENO;
		clean_cmd->tab_fd_out_append[i] = STDOUT_FILENO;
		i++;
	}
	return (SUCCESS);
}

static int	find_fd(int *tab_fd, size_t size, t_cmd *cmd, int std)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (tab_fd[i] == cmd->fd[std])
			return (true);
		i++;
	}
	return (false);
}

static void	get_type_redir(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	cmd->redirection = 0;
	if (cmd->fd[0] != STDIN_FILENO)
	{
		if (find_fd(clean_cmd->tab_fd_in, clean_cmd->count_redir, cmd, IN) == true)
			cmd->redirection = cmd->redirection | F_REDIRECT_IN;
	}
	if (cmd->fd[1] != STDOUT_FILENO)
	{
		if (find_fd(clean_cmd->tab_fd_out, clean_cmd->count_redir, cmd, OUT) == true)
			cmd->redirection = cmd->redirection | F_REDIRECT_OUT;
		if (find_fd(clean_cmd->tab_fd_out_append, clean_cmd->count_redir, cmd, OUT)
					== true)
			cmd->redirection = cmd->redirection | F_REDIRECT_OUT_APPEND;
	}
}

int	process_redirection(t_cmd *cmd, t_clean_cmd *clean_cmd)
{
	if (create_tab_redir(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	if (clean_redir_av(cmd, clean_cmd) == FAILURE)
		return (FAILURE);
	init_tab_fd(clean_cmd);
	if (process_open_file(cmd, clean_cmd) == FAILURE)
	{
		free(clean_cmd->tab_fd_in);
		free(clean_cmd->tab_fd_out);
		free(clean_cmd->tab_fd_out_append);
		return (FILE_FAIL);
	}
	ft_printf("\033[0;32mDEBUG FD FINAL\n\033[0m");//DEBUG
	debug_fd(cmd->fd);
	get_type_redir(cmd, clean_cmd);
	ft_printf("cmd->redirection = %d\n", cmd->redirection);//DEBUG
	free(clean_cmd->tab_fd_in);
	free(clean_cmd->tab_fd_out);
	free(clean_cmd->tab_fd_out_append);
	return (SUCCESS);
}