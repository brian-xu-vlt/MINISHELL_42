#include "line_editor_bonus.h"

t_vector	*get_env(char *env_name)
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
			return (cursor->content);
		cursor = cursor->next;
	}
	return (NOT_FOUND);
}
