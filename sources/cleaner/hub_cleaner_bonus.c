#include "minishell_bonus.h"

static int process_cleaner(t_cmd *cmd)
{
	int ret_cleaner;

	ret_cleaner = cleaner(cmd);
	if (ret_cleaner != SUCCESS)
		return (ret_cleaner);
	//debug_cleaner(cmd);
	return (SUCCESS);
}

static int	handle_condition(t_cmd *cmd, int ret_executor)
{
	if ((cmd->condition == E_YES_AND && ret_executor != SUCCESS) ||
			(cmd->condition == E_NOT_OR && ret_executor == SUCCESS))
	{
		return (FAILURE);
	}
	return (SUCCESS);
}

int hub_cleaner(t_list *job_list)
{
	t_job *job;
	t_list *tmp_cmd_lst;
	t_cmd *cmd;
	int ret_cleaner;
	int	ret_executor;

	ret_cleaner = SUCCESS;
	ret_executor = SUCCESS;
//	debug_jobs(job_list);
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			cmd = tmp_cmd_lst->content;
			ret_executor = handle_condition(cmd, ret_executor);
			if (ret_executor == FAILURE)
				break ;
			ret_cleaner = process_cleaner(cmd);
			if (ret_cleaner != SUCCESS)
				return (ret_cleaner);
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		if (ret_executor == SUCCESS)
			executor(job);
		ret_executor = get_env_value_int(get_env_list(GET), "?");
		job_list = job_list->next;
	}
	return (SUCCESS);
}
