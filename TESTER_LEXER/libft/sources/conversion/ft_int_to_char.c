/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:27:03 by lfallet           #+#    #+#             */
/*   Updated: 2020/06/13 20:29:12 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_to_char(unsigned char *s, int value)
{
	s[0] = (unsigned char)(value);
	s[1] = (unsigned char)(value >> 8);
	s[2] = (unsigned char)(value >> 16);
	s[3] = (unsigned char)(value >> 24);
}
