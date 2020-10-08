#include "minishell_bonus.h"

static t_env	*store_new_env(char *env_name, char *env_value)
{
	t_env		*new_env;
	t_env_data	*env_data;

	env_data = get_env_data(GET);
	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (new_env == NULL)
		exit_routine_le(ERR_MALLOC);
	new_env->env_name = env_name;
	if (env_value != NULL)
	{
		new_env->env_value = vct_new();
		if (new_env->env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		vct_addstr(new_env->env_value, env_value);
	}
	if (env_data->env_lst == NULL)
		env_data->env_lst = ft_lstnew(new_env);
	else
		ft_lstadd_back(&env_data->env_lst, ft_lstnew(new_env));
	return (new_env);
}

static void		update_existing_env(t_env *env_struct, char *new_env_value,
																int overwrite)
{
	if (new_env_value != NULL)
	{
		if (env_struct->env_value == NULL)
			env_struct->env_value = vct_new();
		if (env_struct->env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		if (overwrite == TRUE)
			vct_clear(env_struct->env_value);
		vct_addstr(env_struct->env_value, new_env_value);
	}
}

void			ms_setenv(char *env_name, char *env_value,
											int overwrite, int export_flag)
{
	t_env		*env_node;

	if ((env_node = get_env_struct(env_name)) == NOT_FOUND)
		env_node = store_new_env(env_name, env_value);
	else
	{
		update_existing_env(env_node, env_value, overwrite);
		free(env_name);
	}
	if (export_flag == TRUE)
		env_node->export_flag = TRUE;
	if (env_value != NULL)
		free(env_value);
}

static void		store_env(char *env, int export_flag)
{
	char		*env_name;
	char		*env_value;
	int			overwrite;

	if (env != NULL)
	{
		parse_env(env, &env_name, &env_value, &overwrite);
		ms_setenv(env_name, env_value, overwrite, export_flag);
	}
}

void			ms_putenv(char *env)
{
	store_env(env, FALSE);
	update_envp();  // USEFULL ?....... check in tests
}

void			export_env(char *env)
{
	store_env(env, TRUE);
	update_envp();
}
