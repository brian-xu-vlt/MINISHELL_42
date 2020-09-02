/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_getfirstchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:34:48 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:41:49 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	vct_getfirstchar(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL)
		return ('\0');
	return (vct->str[0]);
}
