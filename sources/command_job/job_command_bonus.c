#include "minishell_bonus.h"

static int	get_command(int type)
{
	if (type == E_ASSIGN)
		return (E_CMD_ASSIGN);
	else if (type == E_LESS_THAN || type == E_GREATER_THAN)
		return (E_CMD_SIMPLE_REDIRECTION);
	else if (type == E_DOUBLE_GREATER)
		return (E_CMD_DOUBLE_REDIRECTION);
	return (E_CMD_AV);
}

static bool	is_end_cmd(t_token *token, t_list **token_list, t_cmd *cmd, t_job *job)
{
	if (is_cmd_sep(token) == true
			|| next_is_end(token_list) == true)
	{
		if (next_is_end(token_list) == true)
			fill_cmd_model(cmd, token, get_command(token->type));
		add_cmd_to_job(job, cmd);
		init_cmd_var(cmd, token_list);
		return (true);
	}
	return (false);
}

static void	is_cmd(t_token *token, t_cmd *cmd)
{
	if (token->type == E_ASSIGN)
		fill_cmd_model(cmd, token, E_CMD_ASSIGN);
	else if (token->type == E_LESS_THAN || token->type == E_GREATER_THAN
			|| token->type == E_DOUBLE_GREATER)
		fill_cmd_model(cmd, token, token->type == E_DOUBLE_GREATER ? 
						E_CMD_DOUBLE_REDIRECTION : E_CMD_SIMPLE_REDIRECTION);
	else
		fill_cmd_model(cmd, token, E_CMD_AV);
}

static t_job	*init_job()
{
	t_job	*job;
	
	job = (t_job *)malloc(sizeof(t_job));
	if (job == NULL)
		return (NULL);
	job->ret = FAILURE;
	job->cmd_lst = NULL;
	return (job);
}

void	process_sep(t_list **head, t_list **jobs)
{
	t_list *token_list = *head;
	t_list	*node_job = NULL;
	t_job	*job;
	t_cmd	cmd;
	t_token	*token;

	job = init_job();
	if (*head == NULL || job == NULL)
		return ;
	init_cmd_var(&cmd, &token_list);
	while (token_list != NULL && is_job_sep(token_list->content) == false)
	{
		token = token_list->content;
		if (token->type == E_END)
		{
			token_list = token_list->next;
			break ;
		}
		if (is_end_cmd(token, &token_list, &cmd, job) == true)
			continue ;
		is_cmd(token, &cmd);
		token_list = token_list->next;
	}
	if (token_list != NULL)
		add_cmd_to_job(job, &cmd);
	node_job = ft_lstnew(job);
	ft_lstadd_back(jobs, node_job);
	*head = token_list;
}

t_list	*get_jobs(t_list *token_list)
{
	t_list	*jobs = NULL;

	ft_printf("\n");//DEBUG
	ft_printf("************************************************************\n");//DEBUG
	while (token_list != NULL)
		process_sep(&token_list, &jobs);
	return (jobs);
}
