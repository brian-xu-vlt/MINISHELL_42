/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:17:36 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:17:39 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_command(int type)
{
	if (type == E_LESS_THAN || type == E_GREATER_THAN)
		return (E_CMD_S_REDIRECTION);
	else if (type == E_DOUBLE_GREATER)
		return (E_CMD_D_REDIRECTION);
	return (E_CMD_AV);
}

int	process_end_cmd(t_list *token_list, t_cmd *cmd, t_job *job)
{
	if (token_list != NULL)
	{
		if (fill_cmd_model(cmd, NULL, RESIZE) == FAILURE)
			return (FAILURE);
		if (add_cmd_to_job(job, cmd) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	process_add_command(t_token *token, t_cmd *cmd, t_list *token_list,
		t_job *job)
{
	int	add_command;

	add_command = FALSE;
	if (is_cmd(token, cmd, add_command) == TRUE)
	{
		if (add_command == TRUE && next_is_cmd_sep(token_list) == false)
		{
			if (fill_cmd_model(cmd, token, RESIZE) == FAILURE)
				return (FAILURE);
			if (add_cmd_to_job(job, cmd) == FAILURE)
				return (FAILURE);
			add_command = FALSE;
		}
		else
			add_command = TRUE;
	}
	return (SUCCESS);
}
