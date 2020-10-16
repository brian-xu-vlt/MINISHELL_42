/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:44:14 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/12 11:25:49 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	true_len;

	str = NULL;
	if (s != NULL)
	{
		true_len = ft_strlen(s);
		if (len > true_len)
			len = true_len;
		if (start > true_len)
			start = (unsigned int)true_len;
		if (start + len > true_len)
			len = true_len - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			ft_memmove(str, s + start, len);
			str[len] = '\0';
		}
	}
	return (str);
}
