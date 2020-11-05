#include "minishell_bonus.h"

void	free_env_list(t_list *env_lst)
{
	if (env_lst != NULL)
	{
		ft_lstclear(&env_lst, del_env_elem);
	}
}

void			free_btree_node(t_btree *node)
{
	free((void *)node);
}

static int		get_env_name_len(const char *env)
{
	int		i;

	i = 0;
	while (env[i] != '\0' && env[i] != '=' && env[i] != '+')
		i++;
	return (i);
}

void			parse_env(const char *env, char **env_name, char **env_value,
															int *overwrite)
{
	int		name_len;
	int		value_len;
	int		plus_sign_offset;

	name_len = get_env_name_len(env);
	*env_name = (char *)ft_calloc(sizeof(char), name_len + 1);
	if (*env_name == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memmove(*env_name, env, name_len);
	if (env[name_len] != '\0')
	{
		*overwrite = (env[name_len] == '+') ? FALSE : TRUE;
		plus_sign_offset = (*overwrite == FALSE) ? 1 : 0;
		value_len = ft_strlen(env) - name_len - 1 - plus_sign_offset;
		*env_value = (char *)ft_calloc(sizeof(char), value_len + 1);
		if (*env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		ft_memmove(*env_value, env + name_len + 1 + plus_sign_offset, value_len);
	}
	else
		*env_value = NULL;
}
