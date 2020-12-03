/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:18:50 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:18:51 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_at_start_or_end_of_line(size_t index, t_vector *cmd_line)
{
	return (index == 0 || index == vct_getlen(cmd_line));
}

void		past_clipboard(void)
{
	int		clipboard_len;
	int		i;
	char	clipboard_content;
	t_le	*le;

	unselect_all();
	le = get_struct(GET);
	if (le != NULL)
	{
		clipboard_len = vct_getlen(le->clipboard);
		if (clipboard_len >= le->scols + le->prompt_len)
			le->screen_flag |= FULL_REFRESH;
		i = 0;
		while (i < clipboard_len)
		{
			clipboard_content = vct_getcharat(le->clipboard, i);
			insert_char_in_vct(clipboard_content);
			move_cursor_right();
			i++;
		}
		if (is_at_start_or_end_of_line(le->vct_index, le->cmd_line) == false)
			move_cursor_left();
	}
}
