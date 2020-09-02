/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_splitchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:05:29 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/08 00:05:42 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_splitchr(t_vector *vct, char c)
{
	t_vector	*new_vct;

	new_vct = NULL;
	if (vct != NULL)
	{
		new_vct = vct_cdup(vct, c);
		vct_popfrom(vct, new_vct->len + 1);
	}
	return (new_vct);
}
