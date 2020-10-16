/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:43:55 by bvalette          #+#    #+#             */
/*   Updated: 2020/05/21 14:00:13 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ret_str;
	int		nbr_dec;

	if (nbr == NULL || base_from == NULL || base_to == NULL)
		return (NULL);
	nbr_dec = ft_atoi_base(nbr, base_from);
	ret_str = ft_itoa_base(nbr_dec, base_to);
	return (ret_str);
}
