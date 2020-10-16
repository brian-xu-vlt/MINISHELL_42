/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:39:32 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/11 15:39:36 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (s[count] == c ? (char *)s + count : NULL);
}
