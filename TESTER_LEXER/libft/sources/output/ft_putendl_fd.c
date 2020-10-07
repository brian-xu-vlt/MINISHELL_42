/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:38:11 by lfallet           #+#    #+#             */
/*   Updated: 2020/06/23 18:23:00 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	return (ft_putchar_fd('\n', fd));
}
