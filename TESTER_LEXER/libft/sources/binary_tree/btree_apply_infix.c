/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:52:08 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/26 17:37:02 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_item_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || applyf == NULL)
		return ;
	btree_apply_item_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_item_infix(root->right, applyf);
}

void	btree_apply_node_infix(t_btree *root, void (*applyf)(t_btree *))
{
	if (root == NULL || applyf == NULL)
		return ;
	btree_apply_node_infix(root->left, applyf);
	applyf(root);
	btree_apply_node_infix(root->right, applyf);
}
