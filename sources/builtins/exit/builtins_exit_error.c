/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:35:10 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:35:12 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(t_vector *vct_av, char *av, char c, int flag)
{
	if (flag == NUMFALSE_LENZERO)
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK,
						print_error(vct_av, av, c, MINUS_PLUS | NUM),
													F_OVERWRITE);
	if (flag == PARSER_FALSE)
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK,
						print_error(vct_av, av, c, NUM), F_OVERWRITE);
	if (flag == RETLONG_TRUE)
		ms_setenv_int(get_env_list(GET), S_QUESTION_MARK,
						print_error(vct_av, av, c, NUM), F_OVERWRITE);
	exit_routine(EXIT_NORMAL);
}
