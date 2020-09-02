/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort_minindex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 18:42:55 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/24 21:33:55 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_bubblesort_minindex(size_t *tab, size_t size)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (i < size)
	{
		if (i + 1 >= size)
			break ;
		if ((tab[i] < tab[i + 1]) && i == 0)
			index = i;
		else if (i != 0 && (tab[i] < tab[i + 1]))
			index = tab[index] < tab[i] ? index : i;
		i++;
	}
	return (index);
}
