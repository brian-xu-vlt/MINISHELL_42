/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print_char_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:47:53 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:47:55 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_char_in_vct(char c)
{
	t_le	*le;

	le = get_struct(GET);
	if (le != NULL)
		safe_vct_addcharat(le->cmd_line, le->vct_index, c);
}

void	handle_print_char(char key)
{
	t_le	*le;

	le = get_struct(GET);
	if (le != NULL)
	{
		if (get_struct(GET)->select_min != UNSET)
			delete_selection(0);
		insert_char_in_vct(key);
		le->vct_index++;
		refresh_command_line();
	}
}
