/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_clen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:40:29 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:26:31 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

size_t	vct_clen(t_vector *vct, char c)
{
	size_t	i;

	i = 0;
	if (vct == NULL)
		return (0);
	while (i < vct->len && vct->str[i] != c)
		i++;
	return (i);
}
