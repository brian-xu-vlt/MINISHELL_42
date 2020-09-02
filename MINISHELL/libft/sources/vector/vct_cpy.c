/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:48:15 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/11 22:54:29 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_cpy(t_vector *dest, t_vector *src)
{
	if (dest == NULL || src == NULL || dest->str == NULL || src->str == NULL)
		return (FAILURE);
	if (src->len + 1 >= dest->size)
	{
		if (vct_resize(dest, src->len + 1) == FAILURE)
			return (FAILURE);
	}
	ft_bzero(dest->str, dest->size);
	ft_memmove(dest->str, src->str, src->len);
	dest->len = src->len;
	return (SUCCESS);
}
