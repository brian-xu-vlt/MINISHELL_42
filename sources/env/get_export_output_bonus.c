#include "minishell_bonus.h"

static void	free_btree_node(t_btree *node)
{
	free((void*)node);
}

static void	print_disambiguate_value(t_vector *env_value)
{
	int			i;
	t_vector	*tmp_env_value;

	if (vct_chr(env_value, '\"') == FAILURE)
		ft_printf("=\"%s\"", vct_getstr(env_value));
	else
	{
		tmp_env_value = vct_dup(env_value);
		if (tmp_env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		i = vct_getlen(env_value);
		while (i >= 0)
		{
			if (vct_getcharat(tmp_env_value, i) == '\"')
				vct_addcharat(tmp_env_value, i, '\\');
			i--;
		}
		ft_printf("=\"%s\"", vct_getstr(tmp_env_value));
		vct_del(&tmp_env_value);
	}
}

static void	print_btree_node(t_btree *node)
{
	t_env		*env;

	env = ((t_env*)node->item);
	ft_printf("export %s", env->env_name);
	if (env->env_value != NULL)
		print_disambiguate_value(env->env_value);
	ft_putstr_fd("\n", STDERR_FILENO);
}

static int	cmp_function(void * env_1, void *env_2)
{
	char		*env_name_1;
	char		*env_name_2;

	env_name_1 = ((t_env*)env_1)->env_name;
	env_name_2 = ((t_env*)env_2)->env_name;
	return (ft_strncmp(env_name_1, env_name_2, ft_strlen(env_name_1) + 1));
}

static void	add_to_btree(t_btree **tree, t_env *env)
{
	if (tree == NULL)
		*tree = btree_create_node(env);
	else
		btree_insert_data(tree, env, cmp_function);
}

void		get_export_output(void)
{
	t_list		*cursor;
	t_env		*content;
	t_btree		*sorted_tree;

	sorted_tree = NULL;
	if ((cursor = get_struct(GET)->env) == NULL)
		return ;
	while (cursor != NULL)
	{
		content = ((t_env *)cursor->content);
		if (content->export_flag == TRUE)
			add_to_btree(&sorted_tree, content);
		cursor = cursor->next;
	}
	if (sorted_tree != NULL)
	{
		btree_apply_node_infix(sorted_tree, print_btree_node);
		btree_apply_node_suffix(sorted_tree, free_btree_node);
	}
}
