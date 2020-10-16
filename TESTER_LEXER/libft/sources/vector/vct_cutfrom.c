/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cutfrom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 16:59:15 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:52:34 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_cutfrom(t_vector *vct, size_t nb_of_char)
{
	if (vct == NULL)
		return (FAILURE);
	if (nb_of_char > vct->len)
		nb_of_char = vct->len;
	vct->len -= nb_of_char;
	ft_bzero(vct->str + vct->len, vct->size - vct->len);
	return (SUCCESS);
}
