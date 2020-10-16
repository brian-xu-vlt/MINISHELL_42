/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 20:06:18 by lfallet           #+#    #+#             */
/*   Updated: 2020/06/22 19:23:47 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>

static int	is_new_line(t_vector *rest, t_vector *vct)
{
	t_vector	*tmp;

	if (vct_chr(rest, '\n') != FAILURE)
	{
		tmp = vct_splitchr(rest, '\n');
		vct_cat(vct, tmp);
		vct_del(&tmp);
		return (TRUE);
	}
	return (FALSE);
}

ssize_t		vct_readline(t_vector *vct, const int fd)
{
	ssize_t			ret;
	static t_vector	*rest = NULL;
	char			buff[BUFFER_SIZE];

	if (vct == NULL || fd < 0)
	{
		vct_del(&rest);
		return (fd == CLEANUP ? IS_EOF : FAILURE);
	}
	rest = rest == NULL ? vct_new() : rest;
	ft_bzero(vct->str, vct->size);
	vct->len = 0;
	if (is_new_line(rest, vct) == TRUE)
		return (IS_LINE);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (vct_addmem(rest, buff, (size_t)ret) == FAILURE)
			return (FAILURE);
		if (is_new_line(rest, vct) == TRUE)
			return (IS_LINE);
	}
	if (ret != FAILURE && rest->len != 0)
		vct_cat(vct, rest);
	vct_del(&rest);
	return (IS_EOF);
}
