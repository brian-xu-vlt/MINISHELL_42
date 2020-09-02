/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_printendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 20:31:59 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 23:03:32 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "unistd.h"

ssize_t	vct_printendl(t_vector *vct)
{
	ssize_t	ret;

	ret = write(STDOUT_FILENO, vct_getstr(vct), vct_getlen(vct));
	if (ret != FAILURE)
		ret += write(STDOUT_FILENO, "\n", 1);
	return (ret);
}
