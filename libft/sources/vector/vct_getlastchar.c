/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_getlastchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:46:43 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/29 17:46:45 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	vct_getlastchar(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL)
		return ('\0');
	return (vct->str[vct_getlen(vct) - 1]);
}
