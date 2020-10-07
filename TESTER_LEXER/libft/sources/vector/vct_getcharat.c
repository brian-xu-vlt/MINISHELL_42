/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_getcharat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 17:59:08 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/15 18:01:26 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	vct_getcharat(t_vector *vct, size_t index)
{
	if (vct == NULL || vct->str == NULL || index > vct_getlen(vct))
		return ('\0');
	return (vct->str[index]);
}
