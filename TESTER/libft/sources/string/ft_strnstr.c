/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:41:27 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/11 16:37:30 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_same_char(char *big, const char *little, size_t len, size_t i)
{
	size_t count;

	count = 0;
	while (little[count] != '\0' && i + count <= len)
	{
		if (big[count] != little[count])
			return (FALSE);
		count++;
	}
	return (little[count] == '\0');
}

char		*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return (big);
	while (big[i] != '\0' && i <= len - 1)
	{
		if (big[i] == little[0] &&
			ft_same_char(big + i, little, len, i) == TRUE)
			return (big + i);
		i++;
	}
	if (little[0] == '\0')
		return ((char *)big);
	return (NULL);
}
