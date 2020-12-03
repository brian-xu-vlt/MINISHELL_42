/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:00 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:16:01 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*get_env_node(t_list *env_lst, const char *target_env_name)
{
	char			*env_name;
	t_list			*cursor;

	if (target_env_name == NULL)
		errno = EINVAL;
	else
	{
		cursor = env_lst;
		while (cursor != NULL && cursor->content != NULL)
		{
			env_name = ((t_env *)cursor->content)->env_name;
			if (ft_strequ(env_name, (char *)target_env_name) == TRUE)
				return (cursor);
			cursor = cursor->next;
		}
	}
	return (NOT_FOUND);
}

t_env		*get_env_struct(t_list *env_lst, const char *env_name)
{
	t_list			*env_node;

	env_node = get_env_node(env_lst, env_name);
	if (env_node != NOT_FOUND)
		return (env_node->content);
	return (NOT_FOUND);
}

t_vector	*get_env_value_vct(t_list *env_lst, const char *env_name)
{
	t_list	*env_node;

	env_node = get_env_node(env_lst, env_name);
	if (env_node != NOT_FOUND)
		return (((t_env *)env_node->content)->env_value);
	return (NOT_FOUND);
}

int			get_env_value_int(t_list *env_lst, const char *env_name)
{
	t_vector		*value_vct;
	char			*value_str;

	errno = 0;
	value_vct = get_env_value_vct(env_lst, env_name);
	if (value_vct != NOT_FOUND && (value_str = vct_getstr(value_vct)) != NULL)
		return (ft_atoi(value_str));
	else
		errno = FAILURE;
	return (0);
}

t_list		*get_env_list(t_list *mem)
{
	static t_list	*mem_backup = NULL;

	if (mem != NULL)
		mem_backup = mem;
	return (mem_backup);
}
