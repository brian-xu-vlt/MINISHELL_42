/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:15:30 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:15:31 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	repartition(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	int	ret_cmd;

	ret_cmd = get_envp_av(cmd, clean_cmd, index_cmd);
	if (ret_cmd == FAILURE)
	{
		free_clean_command(clean_cmd, MALLOC);
		return (FAILURE);
	}
	if (ret_cmd != NO_COMMAND)
	{
		if (process_redirection(cmd, clean_cmd) == FAILURE)
		{
			free_clean_command(clean_cmd, MALLOC);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

static int	process_clean_command(t_cmd *cmd)
{
	t_clean_cmd	*clean_cmd;
	int			index_cmd;

	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd);
	if (index_cmd == ONLY_REDIR_BEFORE)
	{
		cmd->ac = 0;
		free_clean_command(clean_cmd, FREE_ONLY_CMD);
		return (SUCCESS);
	}
	if (repartition(cmd, clean_cmd, index_cmd) == FAILURE)
		return (FAILURE);
	cmd->name = (cmd->ac != 0 ? cmd->av[0] : NULL);
	free_clean_command(clean_cmd, ALL_FREE);
	return (SUCCESS);
}

char		*clean_quote(char *arg, int *ret)
{
	t_vector	*input;
	t_vector	*output;
	char		*transform_arg;
	int			ret_clean;

	input = safe_vct_new();
	output = safe_vct_new();
	*ret = 0;
	safe_vct_addstr(input, arg);
	transform_arg = NULL;
	ret_clean = process_clean_quote(input, output);
	if (ret_clean == FAILURE)
		*ret = 0;
	free(arg);
	if (ret_clean == 2 && ret_clean != FAILURE)
	{
		transform_arg = NULL;
		*ret = 2;
	}
	if (output != NULL && ret_clean != 2 && ret_clean != FAILURE)
		transform_arg = vct_strdup(output);
	vct_del(&input);
	vct_del(&output);
	return (transform_arg);
}

int			cleaner(t_cmd *cmd)
{
	int		ret_cmd;
	size_t	i;
	int		ret;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		cmd->av[i] = clean_quote(cmd->av[i], &ret);
		if (cmd->av[i] == NULL && ret == 0)
		{
			free(cmd->av[i]);
			return (BACKSL_ERROR);
		}
		i++;
	}
	ret_cmd = process_clean_command(cmd);
	return (ret_cmd);
}
