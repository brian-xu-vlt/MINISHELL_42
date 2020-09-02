/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 20:24:23 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:20:45 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "unistd.h"

ssize_t	vct_print_fd(t_vector *vct, int fd)
{
	return (write(fd, vct_getstr(vct), vct_getlen(vct)));
}
