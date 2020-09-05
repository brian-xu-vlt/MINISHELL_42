/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:04 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 11:41:28 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	btree_level_count(t_btree *root)
{
	static size_t	level_left;
	static size_t	level_right;

	if (root == NULL)
		return (0);
	if (root->left != NULL)
		level_left = btree_level_count(root->left);
	if (root->right != NULL)
		level_right = btree_level_count(root->right);
	return ((level_left > level_right) ? level_left + 1 : level_right + 1);
}
