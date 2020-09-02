/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:39:02 by lfallet           #+#    #+#             */
/*   Updated: 2019/11/12 11:12:09 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_tab_str(char ***strs, size_t max_size)
{
	size_t	i;

	i = 0;
	while (i < max_size)
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = NULL;
}

static void		ft_process_split(char ***strs, const char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (len == 0)
			break ;
		(*strs)[i] = ft_substr(s, 0, len);
		if ((*strs)[i] == NULL)
		{
			ft_free_tab_str(strs, i);
			break ;
		}
		i++;
		s += len;
	}
}

static size_t	ft_get_word_count(const char *s, char c)
{
	size_t	word_count;

	word_count = (*s != c && *s != '\0');
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (*s == '\0')
				break ;
			word_count++;
		}
		s++;
	}
	return (word_count);
}

char			**ft_split(char const *s1, char c)
{
	char	**strs;
	size_t	word_count;

	strs = NULL;
	if (s1 != NULL)
	{
		word_count = ft_get_word_count((const char *)s1, c);
		strs = (char **)malloc(sizeof(char *) * (word_count + 1));
		if (strs != NULL)
		{
			strs[word_count] = NULL;
			ft_process_split(&strs, s1, c);
		}
	}
	return (strs);
}
