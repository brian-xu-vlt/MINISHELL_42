/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_popfrom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 16:42:09 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:59:01 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_popfrom(t_vector *vct, size_t nb_of_char)
{
	if (vct == NULL)
		return (FAILURE);
	if (nb_of_char > vct->len)
		nb_of_char = vct->len;
	ft_memmove(vct->str, vct->str + nb_of_char, vct->len - nb_of_char);
	vct->len -= nb_of_char;
	ft_bzero(vct->str + vct->len, vct->size - vct->len);
	return (SUCCESS);
}
