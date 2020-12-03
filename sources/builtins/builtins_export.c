/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:14:37 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:14:40 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool		is_valid_export_identifier(char *id_to_test)
{
	if (id_to_test == NULL)
		return (FAILURE);
	if (ft_strchr(id_to_test, '+') != NOT_FOUND
			&& ft_strnstr(id_to_test, "+=", ft_strlen(id_to_test)) == NOT_FOUND)
		return (false);
	else if (verif_assign_cmd(id_to_test) == false
					&& (ft_isalpha(*id_to_test) == true || *id_to_test == '_'))
		return (true);
	else
		return (false);
}

static void	export_loop(char **av)
{
	int					i;

	i = 1;
	while (av != NULL && av[i] != NULL)
	{
		export_env(get_env_list(GET), av[i]);
		i++;
	}
}

void		export_envp(char **envp)
{
	int					i;

	i = 0;
	if (envp == NULL)
		return ;
	while (envp != NULL && envp[i] != NULL)
		export_env(get_env_list(GET), envp[i++]);
}

int			export_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "export";
	static const char	*usage = "export: usage: export [name[=value] ...]\n";

	if (ft_strequ(av[0], (char *)builtin) == FALSE || av == NULL)
		return (0);
	errno = 0;
	if (ac > 1)
	{
		if (av[1][0] == '-')
		{
			print_invalid_option(builtin, av[1], usage);
			return (2);
		}
		else
			export_loop(av);
	}
	if (ac == 1)
		print_export_output(get_env_list(GET), F_EXPORT_OUTPUT);
	export_envp(envp);
	if (errno == EINVAL)
		return (1);
	return (0);
}
