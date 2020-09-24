#include "minishell_bonus.h"

t_env		*init_env_struct()
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

static void	store_new_env(char *env_name, t_vector *env_value)
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
}

static void	update_existing_env(t_list *env_node, t_vector *new_env_value, int append_flag)
{
	t_vector	*env_value_vct;

	env_value_vct = ((t_env *)(env_node->content))->env_value;
	if (new_env_value == NULL)
		return ;
	else if (env_value_vct == NULL && new_env_value != NULL)
		env_value_vct = vct_new();
	if (append_flag == FALSE)
		vct_clear(env_value_vct);
	vct_cat(env_value_vct, new_env_value);
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

void		store_env(char *env)
{
	char		*env_name;
	t_vector	*env_value;
	int			append_flag;
	t_list		*env_node;

	if (env == NULL)
		return ;
	parse_env(env, &env_name, &env_value, &append_flag);
	if ((env_node = get_env_node(env_name)) == NOT_FOUND)
		store_new_env(env_name, env_value);
	else
	{
		update_existing_env(env_node, env_value, append_flag);
		free(env_name);
		vct_del(&env_value);
	}
}
