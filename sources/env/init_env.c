/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:07 by bvalette          #+#    #+#             */
/*   Updated: 2020/12/03 16:16:08 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		handle_only_pwd(void)
{
	char *pwd;

	pwd = getcwd(NULL, PATH_MAX);
	ms_setenv(get_env_list(GET), ENV_PWD, pwd, F_OVERWRITE | F_EXPORT);
	free(pwd);
}

static void		set_default_env(t_list *env_lst)
{
	handle_only_pwd();
	export_env(env_lst, "OLDPWD");
	ms_putenv(env_lst, DEFAULT_EXIT_STATUS);
	if (vct_getstr(get_env_value_vct(env_lst, "PATH")) == NOT_FOUND)
		ms_putenv(env_lst,
	"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	if (vct_getstr(get_env_value_vct(env_lst, "TERM")) == NOT_FOUND)
		ms_putenv(env_lst, DEFAULT_TERM);
}

static void		manage_shlevel(t_list *env_lst)
{
	int			shlvl_int;

	shlvl_int = get_env_value_int(env_lst, "SHLVL");
	if (shlvl_int < SHLVL_MIN)
		shlvl_int = 0;
	else
		shlvl_int++;
	if (shlvl_int >= SHLVL_MAX)
	{
		ft_dprintf(STDERR_FILENO, "Minishell: warning: shell level"
	"(%d) too high, resetting to 1\n", shlvl_int);
		shlvl_int = 1;
	}
	ms_setenv_int(env_lst, "SHLVL", shlvl_int, F_OVERWRITE | F_EXPORT);
}

static t_list	*init_env_list(void)
{
	t_list		*env_lst;

	env_lst = ft_lstnew(NULL);
	if (env_lst == NULL)
		exit_routine(EXIT_MALLOC);
	get_env_list(env_lst);
	return (env_lst);
}

void			init_env(void)
{
	t_list		*env_lst;
	int			index;
	extern char **environ;

	if (environ == NULL)
		exit_routine(EXIT_ENV);
	env_lst = init_env_list();
	index = 0;
	while (environ[index] != NULL)
	{
		if (is_special_environ(environ[index]) == true)
			ms_setenv(env_lst, environ[index], NULL, F_SPECIAL);
		else
			export_env(env_lst, environ[index]);
		index++;
	}
	set_default_env(env_lst);
	manage_shlevel(env_lst);
}
