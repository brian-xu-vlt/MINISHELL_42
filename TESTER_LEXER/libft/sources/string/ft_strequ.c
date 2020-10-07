/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:10:51 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/04 16:19:26 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char *str1, char *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	size_t	i;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	i = 0;
	if (str1 == NULL || str2 == NULL || (len_str1 != len_str2))
		return (FALSE);
	if (str1 == NULL && str2 == NULL)
		return (TRUE);
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
