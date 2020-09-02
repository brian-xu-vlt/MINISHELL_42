/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:30:47 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 18:58:11 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

ssize_t	vct_chr(t_vector *vct, char c)
{
	size_t	clen;

	if (vct == NULL)
		return (FAILURE);
	clen = vct_clen(vct, c);
	return (clen == vct->len ? FAILURE : (ssize_t)clen);
}
