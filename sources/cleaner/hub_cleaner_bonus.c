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

int hub_cleaner(t_list *job_list)
{
	t_job *job;
	t_list *tmp_cmd_lst;
	t_cmd *cmd;
	int ret_cleaner;

	ret_cleaner = SUCCESS;
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			cmd = tmp_cmd_lst->content;
			ret_cleaner = process_cleaner(cmd);
			if (ret_cleaner != SUCCESS)
				return (ret_cleaner);
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		executor(job);
		job_list = job_list->next;
	}
	return (SUCCESS);
}
