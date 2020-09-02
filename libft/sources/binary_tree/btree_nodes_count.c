/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_nodes_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:04 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/27 08:16:32 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	btree_nodes_count(t_btree *root)
{
	static size_t	node_count;

	if (root == NULL)
		return (0);
	node_count++;
	btree_nodes_count(root->left);
	btree_nodes_count(root->right);
	return (node_count);
}
