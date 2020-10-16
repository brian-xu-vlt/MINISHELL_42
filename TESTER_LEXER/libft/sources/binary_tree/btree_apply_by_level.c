/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:51:04 by bvalette          #+#    #+#             */
/*   Updated: 2020/08/28 11:50:13 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

static void		push_to_queue_level(int *queue_level, t_btree *node_to_push,
															int *end, int level)
{
	if (node_to_push == NULL)
		return ;
	queue_level[*end] = level;
	(*end)++;
}

static void		push_to_queue_address(t_btree **queue_address,
												t_btree *node_to_push, int *end)
{
	if (node_to_push == NULL)
		return ;
	queue_address[*end] = node_to_push;
}

static t_btree	*pop_of_queue(t_btree **queue_address, int *queue_level,
														int *front, int level)
{
	if (queue_level[*front] == level)
	{
		(*front)++;
		return (queue_address[*front - 1]);
	}
	else
		return (NULL);
}

static void		btree_level_traversal(t_btree *root, t_btree ***queue_address,
	int **queue_level, void (*applyf)(void *node, int level, int is_first_elem))
{
	int			front;
	int			end;
	int			level;
	int			max_level;
	t_btree		*node;

	front = 0;
	end = 0;
	level = 1;
	max_level = (int)btree_level_count(root);
	node = root;
	while (level <= max_level && node != NULL)
	{
		applyf(node, level, (level == 1));
		push_to_queue_address(*queue_address, node->left, &end);
		push_to_queue_level(*queue_level, node->left, &end, level + 1);
		push_to_queue_address(*queue_address, node->right, &end);
		push_to_queue_level(*queue_level, node->right, &end, level + 1);
		node = pop_of_queue(*queue_address, *queue_level, &front, level);
		if (node == NULL)
		{
			level++;
			node = pop_of_queue(*queue_address, *queue_level, &front, level);
		}
	}
}

void			btree_apply_by_level(t_btree *root,
					void (*applyf)(void *node, int level, int is_first_elem))
{
	t_btree		**queue_address;
	int			*queue_level;
	size_t		queue_size_max;

	if (root == NULL || applyf == NULL)
		return ;
	queue_size_max = btree_nodes_count(root);
	if (queue_size_max == 1)
	{
		applyf(root, 1, TRUE);
		return ;
	}
	queue_address = (t_btree **)malloc(sizeof(t_btree *) * queue_size_max);
	if (queue_address == NULL)
		return ;
	queue_level = (int *)ft_calloc(sizeof(int), queue_size_max);
	if (queue_level == NULL)
		return (free(queue_address));
	btree_level_traversal(root, &queue_address, &queue_level, applyf);
	free(queue_address);
	free(queue_level);
}
