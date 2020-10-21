#include "minishell_bonus.h"

// TO REMOVE ?


static void	*dup_env_content(void *content)
{
	t_env	*env_struct;
	t_env	*new_env_struct;

	env_struct = (t_env *)content;
	new_env_struct = (t_env *)ft_calloc(sizeof(t_env), 1);
	if (new_env_struct == NULL)
		return (NULL);
	ft_memcpy(new_env_struct, env_struct, sizeof(t_env));
	return (new_env_struct);
}

t_list		*duplicate_env_lst(t_list *env_lst)
{
	t_list	*lst_dup;

	lst_dup = ft_lstmap(env_lst, dup_env_content, del_env_elem);
	if (lst_dup == NULL)
		exit_routine_le(ERR_MALLOC);
	return (lst_dup);
}
