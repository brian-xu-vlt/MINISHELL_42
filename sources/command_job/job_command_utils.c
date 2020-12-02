/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_command_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:42:42 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:42:43 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_data(int type)
{
	if (type == E_GREATER_THAN)
		return (GREATER_THAN);
	else if (type == E_LESS_THAN)
		return (LESS_THAN);
	return (DOUBLE_GREATER);
}

int		get_tablen(char **av)
{
	(void)av;
	return (0);
}

int		next_is_end(t_list **token_list)
{
	t_list	*tmp_list;
	t_token	*token;

	tmp_list = *token_list;
	tmp_list = tmp_list->next;
	if (tmp_list == NULL)
		return (false);
	token = tmp_list->content;
	return (token->type == E_END ? true : false);
}

int		next_is_cmd_sep(t_list *token_list)
{
	t_list	*tmp_list;
	t_token	*token;

	tmp_list = token_list;
	tmp_list = tmp_list->next;
	if (tmp_list == NULL)
		return (false);
	token = tmp_list->content;
	return (is_cmd_sep(token) == true ? true : false);
}
