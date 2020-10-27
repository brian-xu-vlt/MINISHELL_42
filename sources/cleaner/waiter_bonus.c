#include "minishell_bonus.h"

static bool	executor(t_cmd *cmd)
{
	return (true);
}

int	waiter(t_list *job_list)
{
	t_job	*job;
	t_list	*tmp_cmd_lst;
	t_cmd	*cmd;
	bool	ret_exec;
	
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			cmd = tmp_cmd_lst->content;
			if (cmd->condition == E_NONE || 
				(cmd->condition == E_YES_AND && ret_exec == true) ||
				(cmd->condition == E_NOT_OR && ret_exec == false))
			{
				if (cleaner(cmd) == FAILURE)
				{
					ft_printf("CLEANER FAILURE\n");
					return (FAILURE);
				}
				debug_cleaner(cmd);
				ret_exec = executor; //UTILISER LE VRAI EXECUTOR
			}
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		job_list = job_list->next;
	}
	return (SUCCESS);
}
