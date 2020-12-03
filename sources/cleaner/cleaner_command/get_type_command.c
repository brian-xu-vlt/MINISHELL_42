/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:13 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:16:15 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	verif_expect(t_vector *vct, t_vector *vct_cpy)
{
	size_t		id_equal;

	id_equal = vct_clen(vct, ASSIGN);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
	if (ft_isdigit(vct_getfirstchar(vct)) == true ||
			vct_chr(vct, C_PATH) != FAILURE || is_wrong_ass(vct) == false)
	{
		vct_del(&vct);
		vct_del(&vct_cpy);
		return (true);
	}
	return (false);
}

bool		verif_assign_cmd(char *str)
{
	t_vector	*vct;
	t_vector	*vct_cpy;

	vct = safe_vct_new();
	vct_cpy = safe_vct_new();
	safe_vct_addstr(vct, str);
	safe_vct_addstr(vct_cpy, vct_getstr(vct));
	if (verif_expect(vct, vct_cpy) == true)
		return (true);
	vct_del(&vct);
	vct_del(&vct_cpy);
	return (false);
}

static bool	verif_exp_cmd(char *str)
{
	t_vector	*vct;

	vct = safe_vct_new();
	safe_vct_addstr(vct, str);
	if (vct_getfirstchar(vct) == C_EXPORT)
		vct_pop(vct);
	if (is_wrong_ass(vct) == false)
	{
		vct_del(&vct);
		return (true);
	}
	vct_del(&vct);
	return (false);
}

static int	process_get_cmd(size_t i, t_cmd *cmd)
{
	if (cmd->i_assign < (size_t)cmd->count_assign && cmd->count_assign != 0
			&& i == (size_t)cmd->tab_assign[cmd->i_assign])
	{
		if (ft_strchr(cmd->av[i], ASSIGN) == NULL)
			return (TRUE_CMD);
		if (verif_assign_cmd(cmd->av[i]) == false)
			return (TRUE_ASSIGN);
		return (FALSE_ASSIGN);
	}
	else if (cmd->i_exp < (size_t)cmd->count_exp && cmd->count_exp != 0
				&& i == (size_t)cmd->tab_exp[cmd->i_exp])
	{
		if (ft_strchr(cmd->av[i], EXP) == NULL)
			return (TRUE_CMD);
		if (verif_exp_cmd(cmd->av[i]) == false)
			return (TRUE_EXP);
		return (FALSE_EXP);
	}
	return (TRUE_CMD);
}

int			get_cmd(t_cmd *cmd)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		if (check_av(cmd, &i) == true)
			continue ;
		if (is_redir_before(cmd, i) == true)
		{
			if ((i == 0 && cmd->ac == 1) ||
					(cmd->count_exp != 0 && i == cmd->tab_exp[0]))
				return (0);
			how_increment(cmd, &i);
			if (set_redir_before(cmd, i) == ONLY_REDIR_BEFORE)
				return (ONLY_REDIR_BEFORE);
			continue ;
		}
		ret = process_get_cmd(i, cmd);
		if (ret == FALSE_ASSIGN || ret == FALSE_EXP || ret == TRUE_CMD)
			return (i);
		increment(ret, cmd);
		i++;
	}
	return (FAILURE);
}
