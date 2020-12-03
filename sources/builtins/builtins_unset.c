/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:15:23 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:15:24 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	process_valid_identifier(t_vector *vct, char *av_to_check)
{
	char				c_first;

	while (vct != NULL && vct_getlen(vct) > 0)
	{
		c_first = vct_getfirstchar(vct);
		if (ft_isalnum(c_first) == false && c_first != C_EXP &&
		c_first != LOW_LINE)
		{
			print_invalid_identifier("unset", av_to_check);
			vct_del(&vct);
			return (false);
		}
		vct_pop(vct);
	}
	vct_del(&vct);
	return (true);
}

static bool	is_valid_identifier(char *av_to_check)
{
	t_vector			*vct;
	char				c_first;
	char				c_last;

	vct = safe_vct_new();
	safe_vct_addstr(vct, av_to_check);
	c_first = vct_getfirstchar(vct);
	c_last = vct_getcharat(vct, vct_getlen(vct) - 1);
	if (c_last == C_EXP || ft_isdigit(c_first) == true)
	{
		print_invalid_identifier("unset", av_to_check);
		vct_del(&vct);
		return (false);
	}
	return (process_valid_identifier(vct, av_to_check));
}

static int	unset_loop(const char *builtin, const char *usage, char **av)
{
	int					i;
	int					ret;

	ret = BUILTIN_SUCCESS;
	i = 1;
	while (av[i] != NULL)
	{
		if (i < 2 && av[i][0] == '-')
		{
			print_invalid_option(builtin, av[i], usage);
			return (BUILTIN_INVALID_IDENTIFIER);
		}
		if (is_valid_identifier(av[i]) == TRUE)
			unset_env(get_env_list(GET), av[i]);
		else
			ret = BUILTIN_FAILURE;
		i++;
	}
	return (ret);
}

int			unset_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "unset";
	static const char	*usage = "unset: usage: unset [name ...]\n";

	export_envp(envp);
	if (ac == 1 || av == NULL || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else
		return (unset_loop(builtin, usage, av));
}
