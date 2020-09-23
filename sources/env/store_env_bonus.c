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

/*
void		remove_quotes(char **env)
{
	int			i;
	int			env_len;
	char		c;
	t_vector	tmp_env;

	tmp_env = vct_new();
	vct_add(tmp_env, env);
	env_len = vct_getlen(tmp_env);
	i = 0;
	while (i <= env_len)
	{
		c = vct_getcharat(tmp_vct, i);
		if (c == '\"' || c == '\'')
			vct_popcharat(tmp_vct, i);
		i++;
	}

}
*/
void		parse_env(char *env, char **env_name, t_vector **env_value, int *append_flag)
{
	int			env_name_len;

	env_name_len = 0;
	while (env[env_name_len] != '\0'
						&& env[env_name_len] != '=' && env[env_name_len] != '+')
		env_name_len++;
	*env_name = (char *)ft_calloc(sizeof(char), env_name_len + 1);
	if (*env_name == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memmove(*env_name, env, env_name_len);
	if (env[env_name_len] != '\0')
	{
		if (env[env_name_len] == '+')
			*append_flag = TRUE;
		else
			*append_flag = FALSE;
		*env_value = vct_new();
		if (*env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		vct_addstr(*env_value, env + env_name_len + (*(int*)append_flag) + 1); 
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
		update_existing_env(env_node, env_value, append_flag);
}
