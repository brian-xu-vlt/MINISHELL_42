#include "minishell_bonus.h"

void	init_all(t_cmd *cmd)
{
	cmd->name = NULL;
	cmd->av = NULL;
	cmd->type = NULL;
	cmd->fd_string[0] = NULL;
	cmd->fd_string[1] = NULL;
	cmd->fd_string[2] = NULL;
	cmd->condition = E_NONE;
	cmd->condition = E_NONE;
	cmd->redirection = FALSE;
	cmd->redirection_before = FALSE;
	cmd->envp = NULL;
	cmd->tab_redir = NULL;
	cmd->tab_redir_before = NULL;
	cmd->count_redir_before = 0;
	cmd->i_assign = 0;
	cmd->i_exp = 0;
	cmd->ac = 0;
}

void	create_cmd_fd_string(t_cmd *cmd, t_cmd *cmd_model)
{
	if (cmd_model->fd_string[0] != NULL)
		cmd->fd_string[0] = cmd_model->fd_string[0];
	if (cmd_model->fd_string[1] != NULL)
		cmd->fd_string[1] = cmd_model->fd_string[1];
	if (cmd_model->fd_string[2] != NULL)
		cmd->fd_string[2] = cmd_model->fd_string[2];
}

int		resize_cmd(t_cmd *cmd, int count)
{
	if (fill_name(NULL, cmd) == FAILURE)
		return (FAILURE);
	if (fill_assign(FAILURE, count, cmd) == FAILURE)
		return (FAILURE);
	if (fill_exp(FAILURE, count, cmd) == FAILURE)
		return (FAILURE);
	cmd->name = cmd->av[0];
	return (SUCCESS);
}

int		fill_data_cmd(t_token *token, t_cmd *cmd, int count)
{
	if (token->data == NULL)
	{
		if (fill_name(token, cmd) == FAILURE)
			return (FAILURE);
	}
	else
	{
		count = fill_name(token, cmd);
		if (count == FAILURE)
			return (FAILURE);
		if (token->type == E_ASSIGN)
			if (fill_assign(SUCCESS, count, cmd) == FAILURE)
				return (FAILURE);
		if (token->type == E_EXP)
			if (fill_exp(SUCCESS, count, cmd) == FAILURE)
				return (FAILURE);
	}
	return (count);
}
