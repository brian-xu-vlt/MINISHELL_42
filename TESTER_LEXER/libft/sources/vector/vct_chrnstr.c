/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:37:30 by lfallet           #+#    #+#             */
/*   Updated: 2020/09/04 15:37:52 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vct_chrnstr(t_vector *vct, char *str)
{
	size_t	len;

	if (vct == NULL || str == NULL)
		return (FAILURE);
	len = ft_strlen(str);
	return (ft_strncmp(vct_getstr(vct), str, len));
}
