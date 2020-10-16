/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:23:49 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/07 20:57:17 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define FREE_S1 1
# define FREE_S2 2
# define FD_LIMITS 8193

int					get_next_line(int fd, char **line);
int					get_next_line_multifd(int fd, char **line);
char				*ft_strjoinfree(char **s1, char **s2, int is_free);

#endif
