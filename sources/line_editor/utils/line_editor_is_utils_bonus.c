/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor_is_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:50:19 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:50:21 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_shift_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_SHIFT);
}

int		is_ctrl_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_CTRL);
}

int		is_ctrl_shift_on(long buff)
{
	return ((buff & ((long)0xffffff << 16)) >> 16 == K_CTRL_SHIFT);
}
