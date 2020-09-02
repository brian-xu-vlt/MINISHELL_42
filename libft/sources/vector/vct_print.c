/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:35:41 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/02 19:20:04 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "unistd.h"

ssize_t	vct_print(t_vector *vct)
{
	return (write(STDOUT_FILENO, vct_getstr(vct), vct_getlen(vct)));
}
