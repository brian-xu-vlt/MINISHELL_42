/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:38:20 by lfallet           #+#    #+#             */
/*   Updated: 2020/06/23 18:20:15 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

ssize_t	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		if (nb == INT_MIN)
			return (ft_putstr_fd("-2147483648", fd));
		ft_putchar_fd('-', fd);
		return (ft_putnbr_fd(-nb, fd));
	}
	else if (nb < 10)
		return (ft_putchar_fd((char)(nb + 48), fd));
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		return (ft_putnbr_fd(nb % 10, fd));
	}
}
