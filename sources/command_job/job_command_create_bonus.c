#include "minishell_bonus.h"

t_cmd	*create_cmd(t_cmd *cmd_model)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd != NULL)
	{
		ft_bzero(cmd, sizeof(t_cmd));
		//cmd->name = ft_strdup("HELLO");/*cmd_model->av[0]*/
		cmd->av = cmd_model->av;
		cmd->ac = get_tablen(cmd_model->av);
		cmd->fd[0] = STDIN_FILENO;
		cmd->fd[1] = STDOUT_FILENO;
		cmd->fd[2] = STDERR_FILENO;
		cmd->fd_string[0] = cmd_model->fd_string[0];
		cmd->fd_string[1] = cmd_model->fd_string[1];
		cmd->fd_string[2] = cmd_model->fd_string[2];
		cmd->env = cmd_model->env;
		cmd->condition = cmd_model->condition;
		cmd->ret = FAILURE;
	}
	return (cmd);
}

void add_cmd_to_job(t_job *job, t_cmd *cmd_model)
{
	t_cmd 	*cmd;
	t_list	*cmd_node;

	cmd = create_cmd(cmd_model);
	cmd_node = ft_lstnew(cmd);
	ft_lstadd_back(&job->cmd_lst, cmd_node);
}

void	init_cmd_var(t_cmd *cmd, t_list **list)
{
	t_token	*token;

	ft_bzero(cmd, sizeof(t_cmd));
	//ft_printf("INIT COMMAND VAR\n");//
	cmd->av = NULL;
	cmd->fd_string[0] = NULL;
	cmd->fd_string[1] = NULL;
	cmd->fd_string[2] = NULL;
	cmd->env = NULL;
	cmd->condition = E_NONE;
	if (*list != NULL)
	{
		token = (*list)->content;
		if (token->type == E_AND)
			cmd->condition = E_YES_AND;
		else if (token->type == E_OR)
			cmd->condition = E_NOT_OR;
		*list = (*list)->next;
	}
}

void	fill_cmd_model(t_cmd *cmd, t_token *token)
{
	//sert a ajouter le contenu au fur et a mesure
	(void)cmd;
	(void)token;	
}
