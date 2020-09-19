#include "line_editor_bonus.h"

void	print_env(char *env_name)
{
	char	*str;
	t_list	*cursor;

	cursor = get_struct(GET)->env;
	if (env_name == ALL)
	{
		while (cursor != NULL)
		{
			ft_printf("%s\n", vct_getstr(cursor->content));
			cursor = cursor->next;
		}
	}
	else
	{
		str = get_env(env_name);
		if (str != NULL)
			ft_printf("%s\n", str);
	}
}
