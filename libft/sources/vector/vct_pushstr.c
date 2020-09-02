/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_pushstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:07:46 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:27:34 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_pushstr(t_vector *vct, char *str)
{
	size_t	len_str;

	if (vct == NULL || str == NULL)
		return (FAILURE);
	len_str = ft_strlen(str);
	if (len_str + 1 + vct->len >= vct->size)
		if (vct_resize(vct, len_str + 1) == FAILURE)
			return (FAILURE);
	ft_memmove(vct->str + len_str, vct->str, vct->size - len_str);
	ft_memmove(vct->str, str, len_str);
	vct->len += len_str;
	return (SUCCESS);
}
