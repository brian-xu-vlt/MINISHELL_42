/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_addstrat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:21:22 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 18:46:33 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_addstrat(t_vector *vct, size_t index, char *str)
{
	size_t	len_str;
	size_t	i;

	if (vct == NULL || str == NULL || index > vct->len)
		return (FAILURE);
	len_str = ft_strlen(str);
	i = 0;
	if (vct->len + len_str + 1 >= vct->size)
	{
		if (vct_resize(vct, len_str + 1) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + index + len_str, vct->str + index, vct->len - index);
	ft_memmove(vct->str + i + index, str, len_str);
	vct->len += len_str;
	return (SUCCESS);
}
