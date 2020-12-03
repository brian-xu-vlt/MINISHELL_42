/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:34 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:16:35 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*store_new_env(t_list *env_lst, const char *env_name,
														const char *env_value)
{
	t_env	*new_env;

	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (new_env == NULL)
		exit_routine(EXIT_MALLOC);
	new_env->env_name = ft_strdup(env_name);
	if (new_env->env_name == NULL)
		exit_routine(EXIT_MALLOC);
	if (env_value != NULL)
	{
		new_env->env_value = safe_vct_new();
		if (new_env->env_value == NULL)
			exit_routine(EXIT_MALLOC);
		safe_vct_addstr(new_env->env_value, (char *)env_value);
	}
	if (env_lst->content == NULL)
		env_lst->content = new_env;
	else
		ft_lstadd_back(&env_lst, ft_lstnew(new_env));
	return (new_env);
}

static void		update_existing_env(t_env *env_struct,
										const char *new_env_value, int flags)
{
	if (new_env_value != NULL && env_struct != NULL)
	{
		if (env_struct->env_value == NULL)
			env_struct->env_value = safe_vct_new();
		if (flags &= F_OVERWRITE)
			vct_clear(env_struct->env_value);
		safe_vct_addstr(env_struct->env_value, (char *)new_env_value);
	}
}

void			ms_setenv(t_list *env_lst, const char *env_name,
											const char *env_value, int flags)
{
	t_env	*env_node;

	if (env_lst == NULL || env_name == NULL)
		return ;
	if ((env_node = get_env_struct(env_lst, env_name)) == NOT_FOUND)
		env_node = store_new_env(env_lst, env_name, env_value);
	else
		update_existing_env(env_node, env_value, flags);
	if (flags == F_SPECIAL)
		env_node->export_flag = F_SPECIAL;
	else if (flags &= F_EXPORT)
		env_node->export_flag = TRUE;
}

void			ms_setenv_int(t_list *env_lst, const char *env_name,
														int value, int flags)
{
	char	*int_str;

	if (env_lst == NULL || env_name == NULL)
		return ;
	int_str = ft_itoa(value);
	ms_setenv(env_lst, env_name, int_str, flags);
	free(int_str);
}

void			store_env(t_list *env_lst, const char *env, int flags)
{
	char	*env_name;
	char	*env_value;
	int		overwrite;

	overwrite = 0;
	if (env != NULL)
	{
		parse_env(env, &env_name, &env_value, &overwrite);
		flags |= (overwrite == TRUE) ? F_OVERWRITE : F_NOFLAG;
		if (flags & F_EXPORT && is_valid_export_identifier(env_name) == false)
			print_invalid_identifier("export", env);
		else
			ms_setenv(env_lst, env_name, env_value, flags);
		if (env_value != NULL)
			free(env_value);
		free(env_name);
	}
}
