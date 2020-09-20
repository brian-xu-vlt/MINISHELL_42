#include "line_editor_bonus.h"

void	ft_lstdel_node(t_list **lst, t_list *node,  void (*del)(void *))
{
	t_list	*cursor;

	if (del == NULL || lst == NULL || node == NULL)
		return ;
	cursor = *lst;
	if (cursor == node)
	{
		*lst = cursor->next;
		ft_lstdelone(node, del);
		return ;
	}
	while (cursor != NULL)
	{
		if (cursor->next == node)
		{
			cursor->next = cursor->next->next;
			ft_lstdelone(node, del);	
			break ;
		}
		cursor = cursor->next;
	}
}

void	delete_env(char *env_name)
{
	t_list	*env_node;

	if (env_name == NULL)
		return ;
	env_node = get_env_node(env_name);
	if (env_node != NOT_FOUND)
		ft_lstdel_node(&get_struct(GET)->env, env_node, del_vct_content); 
}
