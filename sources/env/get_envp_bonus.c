#include "minishell_bonus.h"

static void	exit_routine_failed_envp(char **envp)
{
	free_envp(envp);
	exit_routine_le(ERR_MALLOC);
}

static char	*create_env(char *env_name, t_vector *env_value)
{
	int		env_name_len;
	int		env_value_len;
	char	*ret_str;

	env_name_len = ft_strlen(env_name);
	env_value_len = vct_getlen(env_value);
	ret_str = (char *)ft_calloc(sizeof(char), env_name_len + env_value_len + 2);
	if (ret_str == NULL)
		exit_routine_le(ERR_MALLOC);
	ft_memmove(ret_str, env_name, env_name_len);
	if (env_value != NULL)
	{
		ft_strcat(ret_str, "=");
		ft_strcat(ret_str, vct_getstr(env_value));
	}
	return (ret_str);
}

void		free_envp(char **envp)
{
	int		i;

	i = 0;
	if (envp == NULL)
		return ;	
	while (envp[i] != NULL)
		free(envp[i++]);
	free(envp);
}

char		**get_envp(void)
{
	int		i;
	int		lst_size;
	t_list	*cursor;
	char	**envp;
	t_env	*content;

	if ((cursor = get_env_data(GET)->env_lst) == NULL)
		return (NULL);
	lst_size = ft_lstsize(cursor);
	if ((envp = (char **)ft_calloc(sizeof(char *), lst_size + 1)) == NULL)
		exit_routine_le(ERR_MALLOC);
	i = 0;
	while (cursor != NULL && i <= lst_size)
	{
		content = ((t_env *)cursor->content);
		if (content->export_flag == TRUE && content->env_value != NULL)
		{
			envp[i] = create_env(content->env_name, content->env_value);
			if (envp[i] == NULL)
				exit_routine_failed_envp(envp);
			i++;
		}
		cursor = cursor->next;
	}
	return (envp);
}
