/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:10:49 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 11:42:41 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
													int (*cmpf)(void *, void *))
{
	void *search_return;

	search_return = NULL;
	if (root != NULL && cmpf != NULL && data_ref != NULL)
	{
		search_return = btree_search_item(root->left, data_ref, cmpf);
		if (cmpf((void *)root->item, (void *)data_ref) == 0)
			return (root->item);
		search_return = btree_search_item(root->right, data_ref, cmpf);
	}
	return (search_return);
}
