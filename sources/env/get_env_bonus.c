#include "minishell_bonus.h"

t_list		*get_env_node(char *env_name)
{
	size_t	name_len;
	char	*str;
	t_list	*cursor;

	if (env_name == NULL)
		return (NOT_FOUND);
	cursor = get_struct(GET)->env;
	name_len = ft_strlen(env_name);
	while (cursor != NULL)
	{
		str = vct_getstr(cursor->content);
		if (ft_strncmp(str, env_name, name_len) == 0
						&& vct_getcharat(cursor->content, name_len) == '=')
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
	return (get_env_struct(env_name)->env_value);
}
