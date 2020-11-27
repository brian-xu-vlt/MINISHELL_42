#include "minishell_bonus.h"

static int	cmp_function(void *env_1, void *env_2)
{
	char		*env_name_1;
	char		*env_name_2;

	if (env_1 == NULL || env_2 == NULL || ((t_env *)env_1)->env_name == NULL)
		exit_routine(EXIT_UNKNOWN);
	env_name_1 = ((t_env*)env_1)->env_name;
	env_name_2 = ((t_env*)env_2)->env_name;
	return (ft_strncmp(env_name_1, env_name_2, ft_strlen(env_name_1) + 1));
}

void		add_to_btree(t_btree **tree, t_env *env)
{
	if (tree == NULL)
		*tree = btree_create_node(env);
	else
		btree_insert_data(tree, env, cmp_function);
}
