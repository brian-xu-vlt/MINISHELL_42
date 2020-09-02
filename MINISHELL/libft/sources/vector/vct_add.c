/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:34:22 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:28:36 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_add(t_vector *vct, char c)
{
	if (vct != NULL && vct->str != NULL)
	{
		if (1 + vct->len >= vct->size)
			if (vct_resize(vct, 1) == FAILURE)
				return (FAILURE);
		vct->str[vct->len] = c;
		vct->len++;
	}
	return (SUCCESS);
}
