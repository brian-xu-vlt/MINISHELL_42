/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export_output_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:35:22 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:35:24 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmp_function(void *env_1, void *env_2)
{
	char	*env_name_1;
	char	*env_name_2;

	if (env_1 == NULL || env_2 == NULL || ((t_env *)env_1)->env_name == NULL)
		exit_routine(EXIT_UNKNOWN);
	env_name_1 = ((t_env*)env_1)->env_name;
	env_name_2 = ((t_env*)env_2)->env_name;
	return (ft_strncmp(env_name_1, env_name_2, ft_strlen(env_name_1) + 1));
}

void		add_to_btree(t_btree **tree, t_env *env)
{
	if (tree == NULL)
		*tree = btree_create_node(env);
	else
		btree_insert_data(tree, env, cmp_function);
}

void		put_env_name_setmode(char *env_name)
{
	if (env_name != NULL)
		ft_putstr_fd(env_name, STDOUT_FILENO);
}

void		put_env_name_exportmode(char *env_name)
{
	if (env_name != NULL)
	{
		ft_putstr_fd("export ", STDOUT_FILENO);
		ft_putstr_fd(env_name, STDOUT_FILENO);
	}
}

void		put_env_value(t_vector *env_value)
{
	if (env_value != NULL)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(vct_getstr(env_value), STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
}
