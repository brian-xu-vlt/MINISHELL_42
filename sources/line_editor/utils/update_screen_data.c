/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:19:58 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:20:02 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_cursor_infos(void)
{
	t_le				*le;

	le = get_struct(GET);
	if (le != NULL && le->prompt_len + le->vct_index != 0)
	{
		le->cy = (le->prompt_len + le->vct_index - 1) / (le->scols);
		if (le->cy > 0)
			le->cx = (le->prompt_len + le->vct_index) - (le->scols / le->cy);
	}
}

void	update_window_size(void)
{
	int				ret;
	struct winsize	w_size;
	t_le			*le;

	le = get_struct(GET);
	if (le != NULL && isatty(STDIN_FILENO) == false)
		exit_routine(EXIT_NO_TTY);
	else if (le != NULL)
	{
		ret = ioctl(STDIN_FILENO, TIOCGWINSZ, &w_size);
		if (ret == FAILURE)
			exit_routine(EXIT_NO_TTY);
		le->srows = w_size.ws_row;
		le->scols = w_size.ws_col;
	}
}
