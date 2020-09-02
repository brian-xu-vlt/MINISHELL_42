/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:17:16 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:52:56 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_dup(t_vector *vct)
{
	t_vector *new_vct;

	if (vct == NULL || vct->str == NULL)
		return (NULL);
	new_vct = vct_new();
	if (vct->len >= new_vct->size)
	{
		if (vct_resize(new_vct, vct->len) == FAILURE)
			return (NULL);
	}
	ft_memmove(new_vct->str, vct->str, vct->len);
	new_vct->len = vct->len;
	return (new_vct);
}
