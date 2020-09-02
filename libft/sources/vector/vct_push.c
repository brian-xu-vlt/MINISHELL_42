/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:07:29 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:25:12 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_push(t_vector *vct, char c)
{
	if (vct == NULL)
		return (FAILURE);
	if (1 + vct->len >= vct->size)
		if (vct_resize(vct, 1) == FAILURE)
			return (FAILURE);
	ft_memmove(vct->str + 1, vct->str, vct->size - 1);
	vct->len++;
	vct->str[0] = c;
	return (SUCCESS);
}
