#include "minishell_bonus.h"

void	put_env(char *env_name, t_vector *env_value)
{
	ft_putstr_fd(env_name, STDERR_FILENO);
	if (env_value != NULL)
		ft_printf("=%s", vct_getstr(env_value));
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_env(char *env_name)
{
	t_vector	*env_value;
	t_list		*cursor;

	cursor = get_struct(GET)->env;
	if (env_name == ALL)
	{
		while (cursor != NULL)
		{
			env_name = ((t_env*)cursor->content)->env_name;
			env_value = ((t_env*)cursor->content)->env_value;
			put_env(env_name, env_value);
			cursor = cursor->next;
		}
	}
	else
	{
		cursor = get_env_node(env_name);	
		env_value = ((t_env*)cursor->content)->env_value;
		put_env(env_name, env_value);
	}
}
