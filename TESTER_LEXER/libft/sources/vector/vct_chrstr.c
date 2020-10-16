/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 19:32:24 by lfallet           #+#    #+#             */
/*   Updated: 2020/09/04 15:29:22 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "stdio.h"

int	vct_chrstr(t_vector *vct, size_t index, char *search)
{
	if (vct == NULL)
		return (FAILURE);
	if (index >= vct->len || ft_strchr(search, vct->str[index]) == NULL)
		return (FALSE);
	return (TRUE);
}
