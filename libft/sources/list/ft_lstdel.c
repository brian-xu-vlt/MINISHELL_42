/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:18:30 by lfallet           #+#    #+#             */
/*   Updated: 2020/10/08 23:36:06 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_delprocess(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		ft_delprocess(lst->next, del);
		if (del != NULL)
			del(lst->content);
		free(lst);
		lst = NULL;
	}
}

void		ft_lstdel(t_list **lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		ft_delprocess(*lst, del);
		*lst = NULL;
	}
}
