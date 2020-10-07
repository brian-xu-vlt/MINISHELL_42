/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:04 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/26 17:37:32 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_item_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || applyf == NULL)
		return ;
	btree_apply_item_suffix(root->left, applyf);
	btree_apply_item_suffix(root->right, applyf);
	applyf(root->item);
}

void	btree_apply_node_suffix(t_btree *root, void (*applyf)(t_btree *))
{
	if (root == NULL || applyf == NULL)
		return ;
	btree_apply_node_suffix(root->left, applyf);
	btree_apply_node_suffix(root->right, applyf);
	applyf(root);
}
