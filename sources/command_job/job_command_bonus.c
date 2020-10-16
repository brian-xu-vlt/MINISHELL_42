#include "minishell_bonus.h"

static int	process_sep(t_list **head, t_list **jobs)
{
	t_list *token_list = *head;
	t_job	*job;
	t_cmd	cmd;
	t_token	*token;

	job = init_job();
	if (*head == NULL || job == NULL)
		return (FAILURE);
	init_cmd_var(&cmd, &token_list);
	while (token_list != NULL && is_job_sep(token_list->content) == false)
	{
		token = token_list->content;
		if (token->type != E_END)
			if (is_add_cmd(token, token_list, &cmd, job) == FAILURE)
				return (FAILURE);
		token_list = token_list->next;
		if (token->type == E_END)
			break ;
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
