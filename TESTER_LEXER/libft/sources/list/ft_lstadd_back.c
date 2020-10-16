/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:33:13 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/12 10:18:49 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (new != NULL)
	{
		begin = *alst;
		if (begin == NULL)
			*alst = new;
		else
		{
			while (begin->next != NULL)
				begin = begin->next;
			begin->next = new;
		}
	}
}
