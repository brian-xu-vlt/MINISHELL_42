/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:39 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:16:40 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		del_env_elem(void *elem_content)
{
	char		*env_name;
	t_vector	*env_value;

	if (elem_content != NULL)
	{
		env_value = ((t_env *)elem_content)->env_value;
		if (env_value != NULL)
			vct_del(&env_value);
		env_name = ((t_env *)elem_content)->env_name;
		free(env_name);
		free(elem_content);
	}
}

static int	is_list_head(t_list *cursor, t_list *node)
{
	return ((cursor == node) ? TRUE : FALSE);
}

static void	ft_lstdel_node(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*cursor;

	if (del == NULL || lst == NULL || node == NULL)
		return ;
	cursor = *lst;
	if (is_list_head(cursor, node) == TRUE)
	{
		*lst = cursor->next;
		get_env_list(*lst);
		ft_lstdelone(node, del);
		return ;
	}
	while (cursor != NULL)
	{
		if (cursor->next == node)
		{
			cursor->next = cursor->next->next;
			ft_lstdelone(node, del);
			break ;
		}
		cursor = cursor->next;
	}
}

void		unset_env(t_list *env_lst, const char *env_name)
{
	t_list	*env_node;

	if (env_name == NULL || ft_isalpha(*env_name) == FALSE)
		return ;
	env_node = get_env_node(env_lst, env_name);
	if (env_node != NOT_FOUND)
		ft_lstdel_node(&env_lst, env_node, del_env_elem);
}
