/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:34:29 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/12 16:20:57 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_addstr(t_vector *vct, char *str)
{
	size_t	len;

	if (vct != NULL && str != NULL)
	{
		len = ft_strlen(str);
		if (len + 1 + vct->len >= vct->size)
			if (vct_resize(vct, len + 1) == FAILURE)
				return (FAILURE);
		ft_memmove(vct->str + vct->len, str, len);
		vct->len += len;
	}
	return (SUCCESS);
}
