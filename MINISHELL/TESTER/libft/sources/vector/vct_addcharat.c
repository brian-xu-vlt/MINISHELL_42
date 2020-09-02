/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addcharat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 10:54:59 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:30:10 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_addcharat(t_vector *vct, size_t index, char c)
{
	if (vct == NULL || index > vct->len)
		return (FAILURE);
	if (vct->len + 2 >= vct->size)
	{
		if (vct_resize(vct, 1) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + index + 1, vct->str + index, vct->len - index);
	vct->str[index] = c;
	vct->len++;
	return (SUCCESS);
}
