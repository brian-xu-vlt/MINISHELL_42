/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:38:09 by lfallet           #+#    #+#             */
/*   Updated: 2020/12/02 18:38:10 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_wrong_ass(t_vector *vct)
{
	t_vector	*vct_cpy;

	vct_cpy = safe_vct_new();
	safe_vct_addstr(vct_cpy, vct_getstr(vct));
	if (vct_getfirstchar(vct_cpy) == LOW_LINE)
		vct_pop(vct_cpy);
	if (vct_getcharat(vct_cpy, vct_getlen(vct_cpy) - 1) == C_PLUS)
		vct_cut(vct_cpy);
	while (vct_getlen(vct_cpy) > 0)
	{
		if (ft_isalnum(vct_getfirstchar(vct_cpy)) == false &&
				vct_getfirstchar(vct_cpy) != LOW_LINE)
		{
			vct_del(&vct_cpy);
			return (false);
		}
		vct_pop(vct_cpy);
	}
	vct_del(&vct_cpy);
	return (true);
}

size_t	verif_assign(t_vector *vct_av, size_t id_equal)
{
	t_vector *vct;

	vct = safe_vct_new();
	safe_vct_cpy(vct, vct_av);
	vct_cutfrom(vct, vct_getlen(vct) - id_equal);
	if (vct_getlen(vct) == 0)
	{
		vct_del(&vct);
		return (false);
	}
	if (ft_isdigit(vct_getfirstchar(vct)) == TRUE)
	{
		vct_del(&vct);
		return (false);
	}
	if (ft_isalnum(vct_getfirstchar(vct)) == false &&
			vct_getfirstchar(vct) != LOW_LINE)
	{
		vct_del(&vct);
		return (false);
	}
	vct_del(&vct);
	return (true);
}
