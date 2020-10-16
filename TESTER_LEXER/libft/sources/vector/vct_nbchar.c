/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_nbchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:46:47 by lfallet           #+#    #+#             */
/*   Updated: 2020/09/05 21:47:07 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

ssize_t	vct_nbchar(t_vector *vct, char *str)
{
	size_t	count;

	count = 0;
	if (vct == NULL)
		return (FAILURE);
	while (vct_getlen(vct) > 0)
	{
		if (ft_strncmp(vct_getstr(vct), str, 1) == SUCCESS)
			count++;
		vct_pop(vct);
	}
	return (count);
}
