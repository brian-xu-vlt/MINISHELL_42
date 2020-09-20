#include "line_editor_bonus.h"

t_list		*get_env_node(char *env_name)
{
	size_t	name_len;
	char	*str;
	t_list	*cursor;

	cursor = get_struct(GET)->env;
	if (env_name == NULL)
		return (NOT_FOUND);
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

t_vector	*get_env_vct(char *env_name)
{
	t_list	*env_node;

	env_node = get_env_node(env_name);
	if (env_name == NULL || env_node == NOT_FOUND)
		return (NOT_FOUND);
	else
		return (env_node->content);
}
