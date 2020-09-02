/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:58:17 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:29:54 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_cat(t_vector *dest, t_vector *src)
{
	if (dest->len + src->len >= dest->size)
	{
		if (vct_resize(dest, src->len) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(dest->str + dest->len, src->str, src->len);
	dest->len += src->len;
	return (SUCCESS);
}
