/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:46:17 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:46:29 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_selection(void)
{
	t_le	*le;
	int		copy_start;
	int		copy_end;
	int		i;

	le = get_struct(GET);
	if (le != NULL)
	{
		vct_clear(le->clipboard);
		if (le->vct_index > (int)vct_getlen(le->cmd_line))
			return ;
		copy_start = (le->select_min == -1) ? le->vct_index : le->select_min;
		copy_end = (le->select_max == -1) ? le->vct_index : le->select_max;
		i = copy_start;
		while (i <= copy_end)
		{
			safe_vct_add(le->clipboard, vct_getcharat(le->cmd_line, i));
			i++;
		}
	}
}
