/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:41:39 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 17:22:54 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strnequ(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	ft_printf("str2 = %s\n", str2);//DEBUG
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	if (str1 == NULL && str2 == NULL)
		return (TRUE);
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
