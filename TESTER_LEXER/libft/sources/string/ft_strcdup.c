/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:12:31 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/04 13:23:11 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s, char c)
{
	char	*str;
	size_t	len_str;

	if (s == NULL)
		return (NULL);
	len_str = ft_strclen(s, c);
	str = (char *)malloc(sizeof(char) * (len_str + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s, len_str);
		str[len_str] = '\0';
	}
	return (str);
}
