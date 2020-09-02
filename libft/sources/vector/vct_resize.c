/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:35:50 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:49:27 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vct_resize(t_vector *vct, size_t len_to_resize)
{
	size_t	new_resize;
	char	*str;

	if (len_to_resize < vct->resize)
		new_resize = vct->resize;
	else
		new_resize = len_to_resize - len_to_resize % vct->resize + vct->resize;
	vct->resize = new_resize;
	vct->size += new_resize;
	str = vct->str;
	vct->str = (char *)malloc(sizeof(char) * (vct->size));
	if (vct->str != NULL)
	{
		ft_bzero(vct->str, vct->size);
		ft_memmove(vct->str, str, vct->len);
	}
	free(str);
	return (vct->str == NULL ? FAILURE : SUCCESS);
}
