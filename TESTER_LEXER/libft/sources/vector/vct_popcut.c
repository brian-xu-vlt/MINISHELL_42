/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_popcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:40:12 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/17 18:09:11 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_popcut(t_vector *vct, size_t end, size_t start)
{
	t_vector	*ret_vct;
	size_t		len;

	if (start > end)
		len = 0;
	else
		len = end - start;
	ret_vct = vct_new();
	if (len + 1 >= ret_vct->size)
		if (vct_resize(ret_vct, len + 1) == FAILURE)
			return (NULL);
	ft_memmove(ret_vct->str, vct->str + start, len);
	ret_vct->len = len;
	return (ret_vct);
}
