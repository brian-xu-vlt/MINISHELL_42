/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:06 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/26 17:37:24 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_item_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || applyf == NULL)
		return ;
	applyf(root->item);
	btree_apply_item_prefix(root->left, applyf);
	btree_apply_item_prefix(root->right, applyf);
}

void	btree_apply_node_prefix(t_btree *root, void (*applyf)(t_btree *))
{
	if (root == NULL || applyf == NULL)
		return ;
	applyf(root);
	btree_apply_node_prefix(root->left, applyf);
	btree_apply_node_prefix(root->right, applyf);
}
