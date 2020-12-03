/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_jobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:20:11 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:20:12 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*test_jobs(t_list *lexer_list)
{
	t_list		*jobs;

	jobs = get_jobs(lexer_list);
	if (jobs == NULL)
		return (NULL);
	return (jobs);
}
