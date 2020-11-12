#include "minishell_bonus.h"

static void	create_cmd_second(t_cmd *cmd, t_cmd *cmd_model)
{
	cmd->count_assign = cmd_model->count_assign;
	cmd->count_exp = cmd_model->count_exp;
	cmd->tab_assign = cmd_model->tab_assign;
	cmd->tab_exp = cmd_model->tab_exp;
	cmd->tmp_fd_in = 0;
	cmd->tmp_fd_out = 1;
	cmd->tmp_fd_append = 1;
	cmd->tab_redir = NULL;
	cmd->count_redir = 0;
	cmd->ret = FAILURE;
}

t_cmd		*create_cmd(t_cmd *cmd_model)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd != NULL)
	{
		ft_bzero(cmd, sizeof(t_cmd));
		cmd->av = cmd_model->av;
		cmd->ac = cmd_model->ac;
		cmd->type = cmd_model->type;
		cmd->fd[0] = STDIN_FILENO;
		cmd->fd[1] = STDOUT_FILENO;
		cmd->fd[2] = STDERR_FILENO;
		create_cmd_fd_string(cmd, cmd_model);
		cmd->condition = cmd_model->condition;
		cmd->redirection = cmd_model->redirection;
		create_cmd_second(cmd, cmd_model);
	}
	return (cmd);
}

int			add_cmd_to_job(t_job *job, t_cmd *cmd_model)
{
	t_cmd	*cmd;
	t_list	*cmd_node;

	cmd_node = NULL;
	cmd = create_cmd(cmd_model);
	if (cmd == NULL)
	{
		free(cmd);
		return (FAILURE);
	}
	cmd_node = ft_lstnew(cmd);
	if (cmd_node == NULL)
	{
		ft_lstdelone(cmd_node, NULL);
		free(cmd_node);
		free(cmd);
		return (FAILURE);
	}
	ft_lstadd_back(&job->cmd_lst, cmd_node);
	return (SUCCESS);
}

void		init_cmd_var(t_cmd *cmd, t_list **list)
{
	t_token	*token;

	ft_bzero(cmd, sizeof(t_cmd));
	cmd->name = NULL;
	cmd->av = NULL;
	cmd->type = NULL;
	cmd->fd_string[0] = NULL;
	cmd->fd_string[1] = NULL;
	cmd->fd_string[2] = NULL;
	cmd->condition = E_NONE;
	cmd->redirection = FALSE;
	cmd->envp = NULL;
	cmd->tab_redir = NULL;
	if (*list != NULL)
	{
		token = (*list)->content;
		cmd->ac = count_ac(list);
		cmd->count_assign = count_assign(list);
		cmd->count_exp = count_exp(list);
		if (token->type == E_AND)
			cmd->condition = E_YES_AND;
		else if (token->type == E_OR)
			cmd->condition = E_NOT_OR;
		*list = (*list)->next;
	}
}

int			fill_cmd_model(t_cmd *cmd, t_token *token, int type)
{
	static int	redirection;
	int			count;

	count = 0;
	if (type == RESIZE)
	{
		if (resize_cmd(cmd, count) == SUCCESS)
			return (SUCCESS);
		return (FAILURE);
	}
	if (redirection != false)
	{
		if (redirection == E_GREATER_THAN || redirection == E_DOUBLE_GREATER)
			cmd->fd_string[1] = token->data;
		else
			cmd->fd_string[0] = token->data;
		cmd->redirection = redirection == E_DOUBLE_GREATER ? true : false;
		redirection = false;
	}
	else if (type == E_CMD_S_REDIRECTION || type == E_CMD_D_REDIRECTION)
		redirection = token->type;
	count = fill_data_cmd(token, cmd, count);
	if (count == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
