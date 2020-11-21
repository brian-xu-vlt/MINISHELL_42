#include "minishell_bonus.h"

static int	process_sep(t_list **head, t_list **jobs)
{
	t_list	*token_list;
	t_job	*job;
	t_cmd	cmd;
	t_token	*token;

	token_list = *head;
	job = init_job();
	if (*head == NULL || job == NULL)
	{
		if (*head == NULL)
			free(job);
		exit_routine_le(ERR_MALLOC);
	}
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

static void	count_nb_command(t_list *job_list)
{
	t_job	*job;
	t_list	*tmp_cmd_lst;
	size_t	count_nb_cmd;

	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		count_nb_cmd = 0;
		while (tmp_cmd_lst != NULL)
		{
			count_nb_cmd++;
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		job->nb_cmd = count_nb_cmd;
		job_list = job_list->next;
	}
}

t_list		*get_jobs(t_list *token_list)
{
	t_list	*jobs;
	int		ret;

	jobs = NULL;
	ret = SUCCESS;
	while (token_list != NULL)
	{
		ret = process_sep(&token_list, &jobs);
		if (ret == FAILURE)
			return (NULL);
	}
	count_nb_command(jobs);
	return (jobs);
}
