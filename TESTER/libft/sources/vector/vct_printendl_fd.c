/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_printendl_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 20:35:46 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:22:56 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "unistd.h"

ssize_t	vct_printendl_fd(t_vector *vct, int fd)
{
	ssize_t	ret;

	ret = write(fd, vct_getstr(vct), vct_getlen(vct));
	if (ret != FAILURE)
		ret += write(fd, "\n", 1);
	return (ret);
}
