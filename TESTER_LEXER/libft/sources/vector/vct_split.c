/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:07:38 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/26 10:40:52 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static t_vector	*process(size_t *i, t_vector *vct_base, char *str,
						const unsigned int flag)
{
	size_t	start;
	size_t	len;

	start = *i;
	len = ft_strlen(str);
	while (*i < vct_base->len)
	{
		if (((flag & WORD) && len != 0
			&& ft_strnequ(str, vct_base->str + *i, len) == TRUE)
			|| ((flag & WORD) == FALSE
			&& vct_chrstr(vct_base, *i, str) == TRUE))
			break ;
		(*i)++;
	}
	return (vct_popcut(vct_base, *i, start));
}

static t_vector	*skip_sep(const unsigned int flag,
							t_vector *vct_base, char *str, size_t *i)
{
	size_t	len;
	size_t	start_flag;

	start_flag = *i;
	if (flag & WORD)
	{
		len = ft_strlen(str);
		while (len != 0 && *i < vct_base->len
			&& ft_strnequ(str, vct_base->str + *i, len) == TRUE)
		{
			if (flag & EACH_SEP)
			{
				*i += len;
				return (vct_popcut(vct_base, *i, start_flag));
			}
			*i += len;
		}
	}
	else
	{
		while (*i < vct_base->len && ft_strchr(str, vct_base->str[*i]) != NULL)
			if (start_flag == (*i)++ && flag & EACH_SEP)
				return (vct_popcut(vct_base, *i, start_flag));
	}
	return (NULL);
}

t_vector		*vct_split(t_vector *vct, char *str, const unsigned int flag)
{
	static t_vector		*vct_base = NULL;
	static size_t		i = 0;
	size_t				start_flag;
	t_vector			*out;

	start_flag = i;
	if (flag == INIT || vct_base == NULL || (vct_base != vct && vct != NULL))
	{
		i = 0;
		vct_base = vct;
		if (vct_base == NULL)
			return (NULL);
	}
	out = skip_sep(flag, vct_base, str, &i);
	if (out == NULL)
	{
		if (flag & ALL_SEP && i != start_flag)
			out = vct_popcut(vct_base, i, start_flag);
		else if (i < vct_base->len)
			out = process(&i, vct_base, str, flag);
		else
			vct_base = NULL;
	}
	i = vct_base == NULL ? 0 : i;
	return (out);
}
