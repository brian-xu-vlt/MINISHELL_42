#include "minishell_bonus.h"

void	process_sep(t_list **head, t_list **jobs)
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
	//debug_token_list(token_list);
	ft_printf("\n");//DEBUG
	init_cmd_var(&cmd, &token_list);
	while (token_list != NULL && is_job_sep(token_list->content) == false)
	{
		token = token_list->content;
		if (token->type == E_END)
		{
			token_list = token_list->next;
			break ;
		}
		if (is_cmd_sep(token_list->content) == true
				|| next_is_end(token_list) == true)
		{
			if (next_is_end(token_list) == true)
				fill_cmd_model(&cmd, token);
			add_cmd_to_job(job, &cmd);
			init_cmd_var(&cmd, &token_list);
			continue ;
		}
		else if (token->type == E_ASSIGN)
			fill_cmd_model(&cmd, token); //->  la string est un  env
		else if (token->type == E_LESS_THAN || token->type == E_GREATER_THAN
					|| token->type == E_DOUBLE_GREATER)
			fill_cmd_model(&cmd, token/*, REDIR_NB*/);	// -> la string est un fd_string
		else
			fill_cmd_model(&cmd, token); //AV);	// -> la string est un av
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
