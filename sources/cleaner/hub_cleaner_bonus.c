#include "minishell_bonus.h"

static int	process_cleaner(t_cmd *cmd)
{
	int ret_cleaner;

	ret_cleaner = cleaner(cmd);
	if (ret_cleaner != SUCCESS)
		return (ret_cleaner);
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

static int	is_next_job(int ret_executor, t_job *job)
{
	if (ret_executor == SUCCESS)
		executor(job);
	ret_executor = get_env_value_int(get_env_list(GET), S_QUESTION_MARK);
	return (ret_executor);
}

int			hub_cleaner(t_list *job_list)
{
	t_job	*job;
	t_list	*tmp_cmd_lst;
	t_cmd	*cmd;
	int		ret;

	ret = SUCCESS;
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			cmd = tmp_cmd_lst->content;
			ret = handle_condition(cmd, ret);
			if (ret == FAILURE)
				break ;
			ret = process_cleaner(cmd);
			if (ret != SUCCESS)
				return (ret);
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		ret = is_next_job(ret, job);
		if (cmd->err_exit == true)
			break ;
		job_list = job_list->next;
	}
	return (SUCCESS);
}
