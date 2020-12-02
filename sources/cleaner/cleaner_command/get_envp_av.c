/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:37:05 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:37:06 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_only_envp(t_cmd *cmd)
{
	size_t	i;
	size_t	new_ac;
	size_t	i_envp;

	i = 0;
	new_ac = count_new_ac(cmd->av, cmd->ac);
	cmd->envp = (char **)malloc(sizeof(char *) * (new_ac + 1));
	if (cmd->envp == NULL)
		return (FAILURE);
	i_envp = 0;
	cmd->envp[new_ac] = NULL;
	while (i < (size_t)cmd->ac)
	{
		if (cmd->av[i] != NULL && ft_strlen(cmd->av[i]) != 0)
		{
			cmd->envp[i_envp] = ft_strdup(cmd->av[i]);
			i_envp++;
		}
		ft_strdel(&cmd->av[i]);
		i++;
	}
	cmd->count_assign = new_ac;
	return (SUCCESS);
}

static int	handle_envp(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)index_cmd)
	{
		if (cmd->av[i] != NULL && ft_strlen(cmd->av[i]) != 0)
			clean_cmd->count_assign++;
		i++;
	}
	cmd->envp = (char **)malloc(sizeof(char *) * (clean_cmd->count_assign + 1));
	if (cmd->envp == NULL)
		return (FAILURE);
	cmd->envp[clean_cmd->count_assign] = NULL;
	i = 0;
	cmd->count_assign = clean_cmd->count_assign;
	fill_envp(cmd, index_cmd);
	return (SUCCESS);
}

static int	handle_get_envp(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	bool	no_cmd;
	int		ret_cmd;

	no_cmd = false;
	if (index_cmd > 0)
		if (handle_envp(cmd, clean_cmd, index_cmd) == FAILURE)
			return (FAILURE);
	if (index_cmd == FAILURE)
	{
		no_cmd = true;
		if (handle_only_envp(cmd) == FAILURE)
			return (FAILURE);
	}
	if (index_cmd == 0)
		cmd->count_assign = 0;
	ret_cmd = clean_cmd_av(cmd, clean_cmd, no_cmd, index_cmd);
	if (ret_cmd == NO_COMMAND)
		return (ret_cmd);
	return (SUCCESS);
}

int			get_envp_av(t_cmd *cmd, t_clean_cmd *clean_cmd, int index_cmd)
{
	int		ret_envp;
	int		ret_clean_cmd;
	int		ret_cmd;

	ret_envp = handle_get_envp(cmd, clean_cmd, index_cmd);
	if (ret_envp != SUCCESS)
		return (ret_envp);
	ret_clean_cmd = fill_clean_cmd(index_cmd, cmd, clean_cmd);
	if (ret_clean_cmd == FAILURE)
		return (FAILURE);
	ret_cmd = fill_cmd(cmd, clean_cmd);
	if (ret_cmd == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
