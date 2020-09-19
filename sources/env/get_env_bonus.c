#include "line_editor_bonus.h"

char	*get_env(char *env_name)
{
	size_t	env_len;
	char	*str;
	t_list	*cursor;

	cursor = get_struct(GET)->env;
	if (env_name == NULL)
		return (NULL);
	env_len = ft_strlen(env_name) - 1;
	while (cursor != NULL)
	{
		str = vct_getstr(cursor->content);
		if (ft_strncmp(str, env_name, env_len) == 0 && str[env_len + 1] == '=')
			return (str);
		cursor = cursor->next;
	}
	return (NULL);
}
