#include "minishell_bonus.h"

static int	get_tablen(char **av)
{
	(void)av;
	return (0);
}

t_cmd	*create_cmd(t_cmd *cmd_model)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd != NULL)
	{
		ft_bzero(cmd, sizeof(t_cmd));
		cmd->name = ft_strdup("HELLO");/*cmd_model->av[0]*/
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


bool	is_job_sep(t_token *token)
{
	return (token->type == E_OR || token->type == E_AND
				|| token->type == E_SEPARATOR ? true : false);
}

void	init_cmd_var(t_cmd *cmd, t_list **list)
{
	t_token	*token;

	ft_bzero(cmd, sizeof(t_cmd));
	ft_printf("YEAH\n");
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
	ft_printf("FILL COMMAND_MODEL\n");//DEBUG*/
	(void)cmd;
	(void)token;	
}

bool	is_cmd_sep(t_token *token)
{
	return (is_job_sep(token) || token->type == E_PIPE);
}

void	add_job_to_list(t_list **head, t_list **jobs)
{
	t_list *token_list = *head;
	t_list	*node_job = NULL;
	t_job	*job;
	t_cmd	cmd;
	t_token	*token;

	if (*head == NULL)
		return ;
	job = (t_job *)malloc(sizeof(t_job));
	if (job == NULL)
		return ;
	job->ret = FAILURE;
	job->cmd_lst = NULL;
	init_cmd_var(&cmd, &token_list);
	while (token_list != NULL && is_job_sep(token_list->content) == false)
	{
		token = token_list->content;
		ft_printf("HELLO\n");//DEBUG
		if (is_cmd_sep(token_list->content) == true)
		{
			add_cmd_to_job(job, &cmd);
			init_cmd_var(&cmd, &token_list);
		}
		else if (token->type != E_ASSIGN)
			fill_cmd_model(&cmd, token);
		else
			fill_cmd_model(&cmd, token);	
		token_list = token_list->next;
	}
	node_job = ft_lstnew(job);
	ft_lstadd_back(jobs, node_job);
	*head = token_list;
}


t_list	*get_jobs(t_list *token_list)
{
	t_list	*jobs = NULL;

	while (token_list != NULL)
		add_job_to_list(&token_list, &jobs);
	return (jobs);
}
