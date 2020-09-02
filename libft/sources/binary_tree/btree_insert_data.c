/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:20 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 12:36:17 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
													int (*cmpf)(void *, void *))
{
	t_btree *tree;

	if (cmpf == NULL)
		return ;
	tree = *root;
	if (*root != NULL)
	{
		if (cmpf(item, tree->item) < 0)
			btree_insert_data(&tree->left, item, cmpf);
		else
			btree_insert_data(&tree->right, item, cmpf);
	}
	else
		*root = btree_create_node(item);
	return ;
}
