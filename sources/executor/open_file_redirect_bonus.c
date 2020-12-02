#include "minishell_bonus.h"

static void init_cmd_redirection(t_cmd *cmd)
{
	if (cmd != NULL)
	{
		if (cmd->fd[0] != STDIN_FILENO && cmd->fd[0] == cmd->tmp_fd_in)
			cmd->redirection = cmd->redirection | F_REDIRECT_IN;
		if (cmd->fd[1] != STDOUT_FILENO && cmd->fd[1] == cmd->tmp_fd_out)
			cmd->redirection = cmd->redirection | F_REDIRECT_OUT;
		if (cmd->fd[1] != STDOUT_FILENO && cmd->fd[1] == cmd->tmp_fd_append)
			cmd->redirection = cmd->redirection | F_REDIRECT_OUT | F_REDIRECT_OUT_APPEND;
	}
}

static int	hub_redirection(int flag, t_cmd *cmd, size_t i)
{
	int	ret_file;

	if (ft_strequ(flag == AFTER ? cmd->tab_redir[i] : cmd->tab_redir_before[i],
			DOUBLE_GREATER) == TRUE)
		ret_file = process_double_greater(flag == AFTER ?
					cmd->tab_redir[i + 1] : cmd->tab_redir_before[i + 1], cmd);
	else if (ft_strequ(flag == AFTER ? cmd->tab_redir[i] :
				cmd->tab_redir_before[i], GREATER_THAN) == TRUE)
		ret_file = process_greater(flag == AFTER ? cmd->tab_redir[i + 1] :
					cmd->tab_redir_before[i + 1], cmd);
	else if (ft_strequ(flag == AFTER ? cmd->tab_redir[i] :
				cmd->tab_redir_before[i], LESS_THAN) == TRUE)
		ret_file = process_less(flag == AFTER ? cmd->tab_redir[i + 1] :
				cmd->tab_redir_before[i + 1], cmd);
	return (ret_file);
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
		ret_file = hub_redirection(flag, cmd, i);
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
