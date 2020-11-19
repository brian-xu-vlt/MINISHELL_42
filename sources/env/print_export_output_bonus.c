#include "minishell_bonus.h"

static void	put_env_name(char *env_name)
{
	ft_putstr_fd("export ", STDOUT_FILENO);
	ft_putstr_fd(env_name, STDOUT_FILENO);
}

static void	put_env_value(t_vector *env_value)
{
	ft_putstr_fd("=\"", STDOUT_FILENO);
	ft_putstr_fd(vct_getstr(env_value), STDOUT_FILENO);
	ft_putstr_fd("\"", STDOUT_FILENO);
}

static void	print_disambiguate_value(t_vector *env_value)
{
	int			i;
	t_vector	*tmp_env_value;

	if (vct_chr(env_value, '\"') == FAILURE)
		put_env_value(env_value);
	else
	{
		tmp_env_value = vct_dup(env_value);
		if (tmp_env_value == NULL)
			exit_routine_le(ERR_MALLOC);
		i = vct_getlen(env_value);
		while (i >= 0)
		{
			if ((vct_getcharat(tmp_env_value, i) == '\"')
								|| (vct_getcharat(tmp_env_value, i) == '\''))
				vct_addcharat(tmp_env_value, i, '\\');
			i--;
		}
		put_env_value(tmp_env_value);
		vct_del(&tmp_env_value);
	}
}

static void	print_btree_node(t_btree *node)
{
	t_env		*env;

	env = ((t_env*)node->item);
	put_env_name(env->env_name);
	if (env->env_value != NULL)
		print_disambiguate_value(env->env_value);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void		print_export_output(t_list *env_lst)
{
	t_list		*cursor;
	t_env		*content;
	t_btree		*sorted_tree;

	if (env_lst == NULL)
		return ;
	sorted_tree = NULL;
	cursor = env_lst;
	while (cursor != NULL && cursor->content != NULL)
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
