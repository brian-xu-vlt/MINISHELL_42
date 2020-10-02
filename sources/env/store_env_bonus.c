#include "minishell_bonus.h"

static t_env	*store_new_env(char *env_name, t_vector *env_value)
{
	t_env		*new_env;
	t_env_data	*env_data;

	env_data = get_env_data(GET);
	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (new_env == NULL)
		exit_routine_le(ERR_MALLOC);
	new_env->env_name = env_name;
	new_env->env_value = env_value;
	if (env_data->env_lst == NULL)
		env_data->env_lst = ft_lstnew(new_env);
	else
		ft_lstadd_back(&env_data->env_lst, ft_lstnew(new_env));
	return (new_env);
}

static void		update_existing_env(t_env *env_struct, t_vector *new_env_value,
																int append_flag)
{
	if (new_env_value != NULL)
	{
		if (env_struct->env_value == NULL)
			env_struct->env_value = vct_new();
		if (env_struct->env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		if (append_flag == FALSE)
			vct_clear(env_struct->env_value);
		vct_cat(env_struct->env_value, new_env_value);
	}
}

static void		store_env(char *env, int export_flag)
{
	char		*env_name;
	t_vector	*env_value;
	int			append_flag;
	t_env		*env_node;

	if (env != NULL)
	{
		parse_env(env, &env_name, &env_value, &append_flag);
		if ((env_node = get_env_struct(env_name)) == NOT_FOUND)
			env_node = store_new_env(env_name, env_value);
		else
		{
			update_existing_env(env_node, env_value, append_flag);
			free(env_name);
			vct_del(&env_value);
		}
		if (export_flag == TRUE)
			env_node->export_flag = TRUE;
	}
}

void			store_internal_var(char *env)
{
	store_env(env, FALSE);
}

void			export_env(char *env)
{
	store_env(env, TRUE);
	update_envp();
}
