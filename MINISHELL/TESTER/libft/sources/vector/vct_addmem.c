/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 22:21:46 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 23:03:32 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_addmem(t_vector *vct, void *mem, size_t len)
{
	if (vct != NULL)
	{
		if (len + 1 + vct->len >= vct->size)
			if (vct_resize(vct, len + 1) == FAILURE)
				return (FAILURE);
		ft_memmove(vct->str + vct->len, mem, len);
		vct->len += len;
	}
	return (SUCCESS);
}
