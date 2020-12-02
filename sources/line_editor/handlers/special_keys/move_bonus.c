/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:47:34 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:47:37 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_end_of_line(void)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)
		ret = move_cursor_right();
	get_struct(GET)->screen_flag |= FULL_REFRESH;
}

void	move_start_of_line(void)
{
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)
		ret = move_cursor_left();
	get_struct(GET)->screen_flag |= FULL_REFRESH;
}

void	move_one_word_right(void)
{
	int		vct_len;
	t_le	*le;

	le = get_struct(GET);
	vct_len = (int)vct_getlen(le->cmd_line);
	while (le->vct_index < vct_len)
	{
		if (vct_getcharat(le->cmd_line, le->vct_index) != ' ')
			break ;
		move_cursor_right();
	}
	while (le->vct_index < vct_len)
	{
		if (vct_getcharat(le->cmd_line, le->vct_index) == ' ')
			break ;
		move_cursor_right();
	}
}

void	move_one_word_left(void)
{
	t_le	*le;

	le = get_struct(GET);
	while (le->vct_index > 0)
	{
		if (vct_getcharat(le->cmd_line, le->vct_index - 1) != ' ')
			break ;
		move_cursor_left();
	}
	while (le->vct_index > 0)
	{
		if (vct_getcharat(le->cmd_line, le->vct_index - 1) == ' ')
			break ;
		move_cursor_left();
	}
}
