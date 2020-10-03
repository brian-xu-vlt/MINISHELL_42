#include "minishell_bonus.h"

t_list		*get_env_node(char *target_env_name)
{
	size_t	target_name_len;
	char	*env_name;
	t_list	*cursor;

	if (target_env_name == NULL || ft_isalpha(target_env_name[0]) == FALSE)
	{
		errno = EINVAL; 
		return (NOT_FOUND);
	}
	cursor = get_env_data(GET)->env_lst;
	target_name_len = ft_strlen(target_env_name);
	while (cursor != NULL)
	{
		env_name = ((t_env *)cursor->content)->env_name;
		if (ft_strncmp(env_name, target_env_name, target_name_len + 1) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NOT_FOUND);
}

t_env		*get_env_struct(char *env_name)
{
	t_list	*env_node;

	env_node = get_env_node(env_name);
	if (env_node != NOT_FOUND)
		return (env_node->content);
	return (NOT_FOUND);
}

t_vector	*get_env_value_vct(char *env_name)
{
	t_list	*env_node;

	env_node = get_env_node(env_name);
	if (env_node != NOT_FOUND)
		return (((t_env *)env_node->content)->env_value);
	return (NOT_FOUND);
}

t_env_data	*get_env_data(t_env_data *mem)
{
	static t_env_data	*mem_backup = NULL;

	if (mem != NULL)
		mem_backup = mem;
	else if (mem == NULL && mem_backup == NULL)
		exit_routine_le(ERR_MALLOC);
	return (mem_backup);
}
