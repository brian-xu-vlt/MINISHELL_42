#include "minishell_bonus.h"

static int	get_command(int type)
{
	if (type == E_LESS_THAN || type == E_GREATER_THAN)
		return (E_CMD_SIMPLE_REDIRECTION);
	else if (type == E_DOUBLE_GREATER)
		return (E_CMD_DOUBLE_REDIRECTION);
	return (E_CMD_AV);
}

static int	is_end_cmd(t_token *token, t_list **token_list, t_cmd *cmd, t_job *job)
{
	if (is_cmd_sep(token) == true
			|| next_is_end(token_list) == true)
	{
		if (next_is_end(token_list) == true)
			fill_cmd_model(cmd, token, get_command(token->type));
		fill_cmd_model(cmd, token, RESIZE);
		if (add_cmd_to_job(job, cmd) == FAILURE)
			return (FAILURE);
		init_cmd_var(cmd, token_list);
		return (true);
	}
	return (false);
}

static int	is_cmd(t_token *token, t_cmd *cmd, int add_command)
{
	if (token->type == E_LESS_THAN || token->type == E_GREATER_THAN
			|| token->type == E_DOUBLE_GREATER)
		fill_cmd_model(cmd, token, token->type == E_DOUBLE_GREATER ? 
				E_CMD_DOUBLE_REDIRECTION : E_CMD_SIMPLE_REDIRECTION);
	else
		fill_cmd_model(cmd, token, E_CMD_AV);
	if (add_command == TRUE)
		return (true);
	return ((token->type == E_LESS_THAN || token->type == E_GREATER_THAN
				|| token->type == E_DOUBLE_GREATER) ? true : false);
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

static int	process_add_command(t_token *token, t_cmd *cmd, t_list *token_list,
		t_job *job)
{
	int	add_command;

	add_command = FALSE;
	if (is_cmd(token, cmd, add_command) == TRUE)
	{
		if (add_command == TRUE && next_is_cmd_sep(token_list) == false)
		{
			fill_cmd_model(cmd, token, RESIZE);
			if (add_cmd_to_job(job, cmd) == FAILURE)
				return (FAILURE);
			add_command = FALSE;
		}
		else
			add_command = TRUE;
	}
	return (SUCCESS);
}

static int	add_job_to_list(t_job *job, t_list **jobs, t_list *token_list,
								t_list **head)
{
	t_list	*node_job = NULL;
	
	node_job = ft_lstnew(job);
	if (node_job == NULL)
	{
		ft_lstdelone(node_job, NULL);
		free(node_job);
		return (FAILURE);
	}
	ft_lstadd_back(jobs, node_job);
	*head = token_list;
	return (SUCCESS);
}

static int	process_end_cmd(t_list *token_list, t_cmd *cmd, t_job *job)
{
	if (token_list != NULL)
	{
		fill_cmd_model(cmd, NULL, RESIZE);
		if (add_cmd_to_job(job, cmd) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	process_sep(t_list **head, t_list **jobs)
{
	t_list *token_list = *head;
	t_job	*job;
	t_cmd	cmd;
	t_token	*token;
	int		ret;

	job = init_job();
	if (*head == NULL || job == NULL)
		return (FAILURE);
	init_cmd_var(&cmd, &token_list);
	while (token_list != NULL && is_job_sep(token_list->content) == false)
	{
		token = token_list->content;
		if (token->type == E_END)
		{
			token_list = token_list->next;
			break ;
		}
		ret = is_end_cmd(token, &token_list, &cmd, job);
		if (ret == true)
			continue ;
		else if (ret == FAILURE)
			return (FAILURE);
		if (process_add_command(token, &cmd, token_list, job) == FAILURE)
			return (FAILURE);
		token_list = token_list->next;
	}
	if (process_end_cmd(token_list, &cmd, job) == FAILURE)
		return (FAILURE);
	if (add_job_to_list(job, jobs, token_list, head) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}


t_list	*get_jobs(t_list *token_list)
{
	t_list	*jobs = NULL;
	int		ret;

	ret = SUCCESS;
	while (token_list != NULL)
	{
		ret = process_sep(&token_list, &jobs);
		if (ret == FAILURE)
			return (NULL);
	}
	return (jobs);
}
