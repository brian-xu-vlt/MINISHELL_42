#include "minishell_bonus.h"

char *exp_value(char *str)
{
	t_vector *vct;

	vct = get_env_value_vct(get_env_list(GET), str);
	return (vct_getstr(vct));
}

bool is_exp_sep(char c)
{
	return (ft_isalnum(c) == false && ft_strchr(EXP_DEL_EXCEPTION, c) == NULL);
}

static void free_clean_command(t_clean_cmd *clean_cmd, int flag,
							   int clean_exp, int *tab_clean_exp)
{
	size_t i;

	i = 0;
	if (flag == ALL_FREE)
	{
		while (i < clean_cmd->ac)
		{
			free(clean_cmd->av[i]);
			i++;
		}
		free(clean_cmd->av);
		i = 0;
		while (i < clean_cmd->count_redir)
		{
			free(clean_cmd->tab_redir[i]);
			i++;
		}
		free(clean_cmd->tab_redir);
		free(clean_cmd->tmp_tab_redir);
		free(clean_cmd->tmp_av);
	}
	if (clean_exp != 0)
		free(tab_clean_exp);
	free(clean_cmd);
}

t_clean_cmd *init_clean_command(void)
{
	t_clean_cmd *clean_cmd;

	clean_cmd = (t_clean_cmd *)malloc(sizeof(t_clean_cmd));
	if (clean_cmd == NULL)
		return (NULL);
	clean_cmd->count_assign = 0;
	clean_cmd->ac = 0;
	clean_cmd->index_export = 0;
	clean_cmd->av = NULL;
	clean_cmd->index_redir = 0;
	clean_cmd->count_redir = 0;
	clean_cmd->tab_redir = NULL;
	clean_cmd->tmp_tab_redir = NULL;
	clean_cmd->tmp_av = NULL;
	clean_cmd->tmp_fd_in = 0;
	clean_cmd->count_other = 0;
	clean_cmd->tmp_fd_out = 1;
	clean_cmd->tmp_fd_append = 1;
	return (clean_cmd);
}

static int process_clean_command(t_cmd *cmd, int *tab_clean_exp,
								 int clean_exp)
{
	t_clean_cmd *clean_cmd;
	int index_cmd;
	int ret_cmd;

	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE, clean_exp, tab_clean_exp);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd);
	ret_cmd = get_envp_av(cmd, clean_cmd, index_cmd);
	if (ret_cmd == FAILURE)
	{
		free_clean_command(clean_cmd, ALL_FREE, clean_exp, tab_clean_exp);
		return (FAILURE);
	}
	if (ret_cmd != NO_COMMAND)
		process_redirection(cmd, clean_cmd);
	cmd->name = (cmd->ac != 0 ? cmd->av[0] : NULL);
	free_clean_command(clean_cmd, ALL_FREE, clean_exp, tab_clean_exp);
	return (SUCCESS);
}

void parse_expansion(t_vector *input, t_vector *output)
{
	t_vector *expansion;
	char *expansion_value;
	char c;

	expansion = vct_new();
	vct_pop(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (is_exp_sep(c) && c != '?')
			break;
		vct_add(expansion, c);
		vct_pop(input);
	}
	if (vct_getlen(expansion) == 0)
		vct_add(output, '$');
	else
	{
		expansion_value = exp_value(vct_getstr(expansion));
		vct_addstr(output, expansion_value);
	}
	vct_del(&expansion);
}

void parse_simple_quote(t_vector *input, t_vector *output)
{
	char c;

	vct_pop(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (c == '\'')
			break;
		vct_add(output, c);
		vct_pop(input);
	}
	vct_pop(input);
}

static int handle_backslash_double(char c, t_vector *input)
{
	vct_pop(input);
	c = vct_getfirstchar(input);
	if (c == '\0')
	{
		ft_printf("ERROR MAGGLE\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

int parse_double_quote(t_vector *input, t_vector *output)
{
	char c;
	char next_c;

	vct_pop(input);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		next_c = vct_getcharat(input, 1);
		if (c == '\\' && (next_c == '$' || next_c == '\"' || next_c == '\\'))
		{
			if (handle_backslash_double(c, input) == FAILURE)
				return (FAILURE);
		}
		else if (c == '$')
		{
			parse_expansion(input, output);
			continue;
		}
		else if (c == '\"')
			break;
		vct_add(output, c);
		vct_pop(input);
	}
	vct_pop(input);
	return (SUCCESS);
}

static int handle_backslash_nothing(t_vector *input, t_vector *output, char c)
{
	vct_pop(input);
	if (c == '\0')
	{
		ft_printf("ERROR MAGGLE\n");
		return (FAILURE);
	}
	vct_add(output, vct_getfirstchar(input));
	vct_pop(input);
	return (SUCCESS);
}

static int handle_char(char c, t_vector *input, t_vector *output)
{
	if (c == '\\')
	{
		if (handle_backslash_nothing(input, output, c) == FAILURE)
			return (FAILURE);
	}
	else if (c == '\'')
		parse_simple_quote(input, output);
	else if (c == '\"')
	{
		if (parse_double_quote(input, output) == FAILURE)
			return (FAILURE);
	}
	else if (c == '$')
		parse_expansion(input, output);
	else
	{
		vct_add(output, c);
		vct_pop(input);
	}
	return (SUCCESS);
}

static int process_transform(t_vector *input, t_vector *output)
{
	char c;

	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (handle_char(c, input, output) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

char *transform(char *arg)
{
	t_vector *input;
	t_vector *output;
	char *transform_arg;

	input = vct_new();
	output = vct_new();
	vct_addstr(input, arg);
	transform_arg = NULL;
	if (process_transform(input, output) == FAILURE)
	{
		vct_del(&input);
		vct_del(&output);
		return (NULL);
	}
	free(arg);
	if (output != NULL)
		transform_arg = vct_strdup(output);
	vct_del(&input);
	vct_del(&output);
	return (transform_arg);
}

int cleaner(t_cmd *cmd)
{
	int ret_cmd;
	size_t clean_exp;
	int *tab_clean_exp;
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		cmd->av[i] = transform(cmd->av[i]);
		if (cmd->av[i] == NULL)
		{
			free(cmd->av[i]);
			return (BACKSL_ERROR);
		}
		i++;
	}
	tab_clean_exp = NULL;
	clean_exp = 0;
	ret_cmd = process_clean_command(cmd, tab_clean_exp, clean_exp);
	return (ret_cmd);
}
