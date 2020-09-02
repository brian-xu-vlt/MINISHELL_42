/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:55:24 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:55:54 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_cdup(t_vector *vct, char c)
{
	t_vector	*new_vct;
	size_t		clen;

	if (vct == NULL || vct->str == NULL)
		return (NULL);
	new_vct = vct_new();
	clen = ft_strclen(vct->str, c);
	if (clen >= new_vct->size)
	{
		if (vct_resize(new_vct, clen) == FAILURE)
			return (NULL);
	}
	ft_memmove(new_vct->str, vct->str, clen);
	new_vct->len = clen;
	return (new_vct);
}
