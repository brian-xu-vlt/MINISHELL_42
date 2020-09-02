/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:42:51 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/12 11:34:26 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

char	*ft_strtrim(char *s1, char *set)
{
	char	*str;
	size_t	beg;
	ssize_t	end;
	size_t	len_s1;

	str = NULL;
	if (set == NULL && s1 != NULL)
		str = ft_strdup(s1);
	else if (s1 != NULL)
	{
		beg = 0;
		len_s1 = ft_strlen(s1);
		end = (ssize_t)len_s1;
		if (len_s1 > 0)
			end--;
		while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
			beg++;
		while (end >= 0 && ft_strchr(set, s1[end]) != NULL)
			end--;
		str = ft_substr(s1, (unsigned int)beg, ((size_t)(end) - beg + 1));
	}
	return (str);
}
