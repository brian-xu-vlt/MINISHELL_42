#include "minishell_bonus.h"

static void	put_env_name_setmode(char *env_name)
{
	if (env_name != NULL)
		ft_putstr_fd(env_name, STDOUT_FILENO);
}

static void	put_env_name_exportmode(char *env_name)
{
	if (env_name != NULL)
	{
		ft_putstr_fd("export ", STDOUT_FILENO);
		ft_putstr_fd(env_name, STDOUT_FILENO);
	}
}

static void	put_env_value(t_vector *env_value)
{
	if (env_value != NULL)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(vct_getstr(env_value), STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
}

static void	append_value_slashs(t_vector *env_value, t_vector *tmp_env_value)
{
	int			i;
	int			ret;
	char		char_at_index;

	ret = SUCCESS;
	i = vct_getlen(env_value);
	while (i >= 0)
	{
		char_at_index = vct_getcharat(tmp_env_value, i);
		if (char_at_index == '\"' || char_at_index == '\'')
			safe_vct_addcharat(tmp_env_value, i, '\\');
		i--;
	}
}

static void	print_disambiguate_value(t_vector *env_value)
{
	t_vector	*tmp_env_value;

	if (env_value == NULL)
		return ;
	if (vct_chr(env_value, '\"') == FAILURE)
		put_env_value(env_value);
	else
	{
		tmp_env_value = vct_dup(env_value);
		if (tmp_env_value == NULL)
			exit_routine(EXIT_MALLOC);
		append_value_slashs(env_value, tmp_env_value);
		put_env_value(tmp_env_value);
		vct_del(&tmp_env_value);
	}
}

static void	print_btree_node_setmode(t_btree *node)
{
	t_env		*env;

	if (node != NULL && (env = ((t_env*)node->item)) != NULL)
	{
		put_env_name_setmode(env->env_name);
		print_disambiguate_value(env->env_value);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

static void	print_btree_node_exportmode(t_btree *node)
{
	t_env		*env;

	if (node != NULL && (env = ((t_env*)node->item)) != NULL)
	{
		put_env_name_exportmode(env->env_name);
		print_disambiguate_value(env->env_value);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

void		print_export_output(t_list *env_lst, int flag)
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
		if ((flag == F_EXPORT_OUTPUT && content->export_flag == TRUE)
		|| (flag == F_SET_OUTPUT && content->env_value != NULL))
			add_to_btree(&sorted_tree, content);
		cursor = cursor->next;
	}
	if (sorted_tree != NULL)
	{
		if (flag == F_EXPORT_OUTPUT)
			btree_apply_node_infix(sorted_tree, print_btree_node_exportmode);
		else if (flag == F_SET_OUTPUT)
			btree_apply_node_infix(sorted_tree, print_btree_node_setmode);
		btree_apply_node_suffix(sorted_tree, free_btree_node);
	}
}
