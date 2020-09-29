#include "minishell_bonus.h"

void		del_env_elem(void *elem_content)
{
	char		*env_name;
	t_vector	*env_value;

	env_value = ((t_env *)elem_content)->env_value;
	if (env_value != NULL)
		vct_del(&env_value);
	env_name = ((t_env *)elem_content)->env_name;
	free(env_name);
	free(elem_content);
}

static void	ft_lstdel_node(t_list **lst, t_list *node, void (*del)(void *))
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

void		delete_env(char *env_name)
{
	t_list	*env_node;

	if (env_name == NULL)
		return ;
	env_node = get_env_node(env_name);
	if (env_node != NOT_FOUND)
		ft_lstdel_node(&get_env_data(GET)->env_lst, env_node, del_env_elem);
	update_envp();
}
