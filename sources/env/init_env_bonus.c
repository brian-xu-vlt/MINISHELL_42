#include "line_editor_bonus.h"

void		init_env(char **env)
{
	int		index;
	t_list	*env_lst;
	t_list	*new_elem;

	if (env == NULL)
		exit_routine_le(ERR_ENV);
	env_lst = NULL;
	index = 0;
	while (env[index] != NULL)
	{
		new_elem = ft_lstnew(vct_new());
		if (new_elem == NULL || new_elem->content == NULL)
			exit_routine_le(ERR_MALLOC);
		vct_addstr(new_elem->content, env[index]);
		if (env_lst != NULL)
			ft_lstadd_back(&env_lst, new_elem);
		else
			env_lst = new_elem;
		index++; 
	}
	get_struct(GET)->env = env_lst;
}
