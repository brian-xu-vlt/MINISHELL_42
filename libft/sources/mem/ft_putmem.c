/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 22:02:48 by bvalette          #+#    #+#             */
/*   Updated: 2020/05/29 21:31:24 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add reversebit to output it in a more human way ?
** n_byte should be the n_bytes of ptr, if different behaviour is undefined
*/

void	ft_putmem(void *ptr, size_t n_bytes)
{
	size_t			i;
	unsigned char	*casted_ptr;
	char			*buffer;

	if (ptr == NULL || n_bytes == 0)
		return ;
	casted_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < n_bytes)
	{
		buffer = ft_itoa_base(casted_ptr[i], "0123456789abcdef");
		if (buffer == NULL || ft_strlen(buffer) == 0)
			return ;
		if (buffer[1] == '\0')
			ft_putchar('0');
		ft_putstr(buffer);
		if (i != n_bytes - 1)
			ft_putchar(' ');
		buffer += 2;
		i++;
	}
}
