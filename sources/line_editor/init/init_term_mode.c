/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:19:42 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:19:43 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_termios(const struct termios *termios_mode)
{
	if (termios_mode != NULL)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, termios_mode);
}

void	init_term_mode(void)
{
	t_le			*le;

	le = get_struct(GET);
	le->termios_editor = (struct termios *)ft_calloc(sizeof(struct termios), 1);
	if (le->termios_editor == NULL)
		exit_routine(EXIT_MALLOC);
	le->termios_bkup = (struct termios *)ft_calloc(sizeof(struct termios), 1);
	if (le->termios_bkup == NULL)
		exit_routine(EXIT_MALLOC);
	tcgetattr(STDIN_FILENO, le->termios_bkup);
	ft_memmove(le->termios_editor, le->termios_bkup, sizeof(struct termios));
	le->termios_editor->c_lflag &= ~(ICANON);
	le->termios_editor->c_lflag &= ~(ECHO);
	le->termios_editor->c_cc[VMIN] = 1;
	le->termios_editor->c_cc[VTIME] = 0;
	set_termios(le->termios_editor);
}
