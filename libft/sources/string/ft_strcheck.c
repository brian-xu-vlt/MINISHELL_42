/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 21:22:12 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/09 21:26:51 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck(char *s, int (*f)(int))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (FALSE);
	i = 0;
	while (s[i] != '\0')
	{
		if (f(s[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
