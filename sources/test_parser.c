/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:20:25 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/03 16:20:26 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_parser(t_list *lexer_list)
{
	if (parser_token(lexer_list) == FALSE)
		return (FALSE);
	return (TRUE);
}
