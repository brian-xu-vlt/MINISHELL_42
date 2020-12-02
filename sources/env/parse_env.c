/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:36:33 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/02 18:36:34 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_name_len(const char *env)
{
	int		i;

	i = 0;
	while (env[i] != '\0')
	{
		if (env[i] == '=' || (env[i] == '+' && env[i + 1] == '='))
			break ;
		i++;
	}
	return (i);
}

static int	is_valid_arg(const char *env, char **env_name, char **env_value,
															int *overwrite)
{
	return (env != NULL && env_name != NULL
		&& env_value != NULL && overwrite != NULL);
}

void		parse_env(const char *env, char **env_name, char **env_value,
															int *overwrite)
{
	int		name_len;
	int		value_len;
	int		sign_offset;

	if (is_valid_arg(env, env_name, env_value, overwrite) == FALSE)
		return ;
	name_len = get_env_name_len(env);
	*env_name = (char *)ft_calloc(sizeof(char), name_len + 1);
	if (*env_name == NULL)
		exit_routine(EXIT_MALLOC);
	ft_memmove(*env_name, env, name_len);
	*env_value = NULL;
	if (env[name_len] != '\0')
	{
		*overwrite = (env[name_len] == '+') ? FALSE : TRUE;
		sign_offset = (*overwrite == FALSE) ? 1 : 0;
		value_len = ft_strlen(env) - name_len - 1 - sign_offset;
		if (value_len >= 0)
		{
			*env_value = (char *)ft_calloc(sizeof(char), value_len + 1);
			if (*env_value == NULL)
				exit_routine(EXIT_MALLOC);
			ft_memmove(*env_value, env + name_len + 1 + sign_offset, value_len);
		}
	}
}
