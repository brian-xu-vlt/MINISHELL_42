/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:20 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 11:40:29 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_node;

	new_node = (t_btree *)malloc(sizeof(t_btree) * 1);
	if (new_node != NULL)
	{
		new_node->item = item;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return (new_node);
}
