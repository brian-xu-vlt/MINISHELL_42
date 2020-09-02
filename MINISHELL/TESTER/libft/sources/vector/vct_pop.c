/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 20:46:53 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:19:12 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vct_pop(t_vector *vct)
{
	if (vct == NULL)
		return (FAILURE);
	if (vct->len == 0)
		return (SUCCESS);
	ft_memmove(vct->str, vct->str + 1, vct->len);
	vct->str[vct->len - 1] = '\0';
	vct->len--;
	return (SUCCESS);
}
