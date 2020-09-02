/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:53:46 by lfallet           #+#    #+#             */
/*   Updated: 2020/03/09 15:52:08 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoinfree(char **s1, char **s2, int is_free)
{
	char	*str;
	size_t	len_str;

	if (*s1 != NULL && *s2 != NULL)
	{
		len_str = ft_strlen(*s1) + ft_strlen(*s2);
		str = (char *)malloc(sizeof(char) * (len_str + 1));
		if (str != NULL)
		{
			ft_memcpy(str, *s1, ft_strlen(*s1));
			ft_memcpy(str + ft_strlen(*s1), *s2, ft_strlen(*s2));
			str[len_str] = '\0';
		}
	}
	else
		str = *s1 == NULL ? ft_strndup(*s2, ft_strlen(*s2)) :
			ft_strndup(*s1, ft_strlen(*s1));
	free(*s1);
	*s1 = NULL;
	if (is_free == FREE_S2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (str);
}
