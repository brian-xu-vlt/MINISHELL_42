/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_free_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:04 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/26 17:39:33 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_free_suffix(t_btree *root)
{
	if (root != NULL)
	{
		btree_free_suffix(root->left);
		btree_free_suffix(root->right);
		if (root->item != NULL)
			free(root->item);
		free(root);
	}
}
