/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:42:26 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/12 16:24:50 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

char	*ft_strrchr(char *s, int c)
{
	ssize_t	i;

	i = (ssize_t)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (s + i);
		i--;
	}
	return (NULL);
}
