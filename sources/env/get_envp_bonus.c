#include "minishell_bonus.h"

char		*get_env_value_str(char *var)
{
	t_vector	*vct;
	char		*str;

	vct = get_env_value_vct(get_env_list(GET), var);
	if (vct == NULL)
		return (NULL);
	str = vct_getstr(vct);
	return (str);
}

static void	exit_routine_failed_envp(char **envp)
{
	free_char_arr(envp);
	exit_routine(EXIT_MALLOC);
}

static char	*create_env(const char *env_name, t_vector *env_value)
{
	int		env_name_len;
	int		env_value_len;
	char	*env_value_str;
	char	*ret_str;

	env_name_len = ft_strlen(env_name);
	env_value_len = vct_getlen(env_value);
	ret_str = (char *)ft_calloc(sizeof(char), env_name_len + env_value_len + 2);
	if (ret_str == NULL)
		exit_routine(EXIT_MALLOC);
	ft_memmove(ret_str, env_name, env_name_len);
	env_value_str = vct_getstr(env_value);
	if (env_value_str != NULL)
	{
		ft_strcat(ret_str, "=");
		ft_strcat(ret_str, env_value_str);
	}
	return (ret_str);
}

static char	**allocate_envp(const t_list *env_lst, int *lst_size)
{
	char	**envp;

	*lst_size = ft_lstsize((t_list *)env_lst);
	envp = (char **)ft_calloc(sizeof(char *), *lst_size + 1);
	if (envp == NULL)
		exit_routine(EXIT_MALLOC);
	return (envp);
}

char		**get_envp(t_list *env_lst)
{
	int		i;
	t_list	*cursor;
	int		lst_size;
	char	**envp;
	t_env	*content;

	if (env_lst == NULL)
		return (NULL);
	envp = allocate_envp(env_lst, &lst_size);
	cursor = env_lst;
	i = 0;
	while (cursor != NULL && cursor->content != NULL && i <= lst_size)
	{
		content = ((t_env *)cursor->content);
		if ((content->export_flag == TRUE && content->env_value != NULL)
		|| content->export_flag == F_SPECIAL)
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
