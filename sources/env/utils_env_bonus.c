#include "minishell_bonus.h"

void			free_btree_node(t_btree *node)
{
	free((void *)node);
}

static int		get_env_name_len(char *env)
{
	int		i;

	i = 0;
	while (env[i] != '\0' && env[i] != '=' && env[i] != '+')
		i++;
	return (i);
}

void			parse_env(char *env, char **env_name, t_vector **env_value,
															int *append_flag)
{
	int		name_len;

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
