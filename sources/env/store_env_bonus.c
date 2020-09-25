#include "minishell_bonus.h"

t_env			*init_env_struct()
{
	t_env		*new_env_struct;

	new_env_struct = (t_env *)malloc(sizeof(t_env));
	if (new_env_struct != NULL)
	{
		new_env_struct->env_name = NULL;
		new_env_struct->env_value = NULL;
		new_env_struct->export_flag = FALSE;
	}
	else
		exit_routine_le(ERR_MALLOC);
	return (new_env_struct);
}

static t_env	*store_new_env(char *env_name, t_vector *env_value)
{
	t_le		*le;
	t_env		*new_env;

	le = get_struct(GET);
	new_env = init_env_struct();
	new_env->env_name = env_name;
	new_env->env_value = env_value;
	if (le->env == NULL)
		le->env = ft_lstnew(new_env);
	else
		ft_lstadd_back(&le->env, ft_lstnew(new_env));
	return (new_env);
}

static void		update_existing_env(t_env *env_struct, t_vector *new_env_value, int append_flag)
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

static int		get_env_name_len(char *env)
{
	int			i;

	i = 0;
	while (env[i] != '\0' && env[i] != '=' && env[i] != '+')
		i++;
	return (i);
}

static void		parse_env(char *env, char **env_name, t_vector **env_value, int *append_flag)
{
	int			name_len;

	name_len = get_env_name_len(env);
	*env_name = (char *)ft_calloc(sizeof(char), name_len + 1);
	if (*env_name == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memmove(*env_name, env, name_len);
	if (env[name_len] != '\0')
	{
		*append_flag = (env[name_len] == '+') ? TRUE : FALSE;
		*env_value = vct_new();
		if (*env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		vct_addstr(*env_value, env + name_len + (*(int*)append_flag) + 1);
	}
	else
		*env_value = NULL;
}

static void		store_env(char *env, int export_flag)
{
	char		*env_name;
	t_vector	*env_value;
	int			append_flag;
	t_env		*env_node;

	if (env == NULL)
		return ;
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

void		store_internal_var(char *env)
{
	store_env(env, FALSE);
}

void		export_env(char *env)
{
	store_env(env, TRUE);
}
