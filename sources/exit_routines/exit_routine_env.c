/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routine_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:17:58 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:17:59 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exit_routine_env(void)
{
	t_list		*env_lst;

	env_lst = get_env_list(GET);
	if (env_lst != NULL)
		free_env_list(env_lst);
}
