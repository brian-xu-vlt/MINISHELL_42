/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:36:50 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:36:51 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	t_job		*job;
	t_list		*tmp_cmd_lst;
	t_cmd		*cmd;
	static int	ret;

	cmd = NULL;
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL && tmp_cmd_lst->content != NULL)
		{
			cmd = tmp_cmd_lst->content;
			if ((ret = handle_condition(cmd, ret)) == FAILURE)
				break ;
			if ((ret = process_cleaner(cmd)) != SUCCESS)
				return (ret);
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		ret = is_next_job(ret, job);
		if (job->cmd_lst != NULL && cmd->err_exit == true)
			break ;
		job_list = job_list->next;
	}
	return (SUCCESS);
}
