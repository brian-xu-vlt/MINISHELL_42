/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exec_context.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:17:20 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:17:21 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	assign_envp_content(const t_cmd *command)
{
	t_list	*env_lst;
	int		i;

	i = 0;
	env_lst = get_env_list(GET);
	while (i < command->count_assign)
	{
		ms_putenv(env_lst, command->envp[i]);
		i++;
	}
}
