/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:32:50 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:29:07 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_join(t_vector *vct1, t_vector *vct2)
{
	t_vector *new_vct;

	new_vct = vct_new();
	vct_cpy(new_vct, vct1);
	vct_cat(new_vct, vct2);
	return (new_vct);
}
