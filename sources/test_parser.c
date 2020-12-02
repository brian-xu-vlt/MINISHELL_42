/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:51:23 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:51:24 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_parser(t_list *lexer_list)
{
	if (parser_token(lexer_list) == FALSE)
		return (FALSE);
	return (TRUE);
}
