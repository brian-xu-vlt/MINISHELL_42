/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:54:58 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/10 17:13:54 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memdup(void *s, size_t len)
{
	void	*ptr;

	ptr = NULL;
	if (s != NULL)
	{
		ptr = malloc(len + 1);
		ptr = ft_memcpy(ptr, s, len);
		((char *)ptr)[len] = '\0';
	}
	return (ptr);
}
