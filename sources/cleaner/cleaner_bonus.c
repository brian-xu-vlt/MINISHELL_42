#include "minishell_bonus.h"

static void	free_clean_command(t_clean_cmd *clean_cmd, int flag,
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

t_clean_cmd	*init_clean_command(void)
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

static int	process_clean_command(t_cmd *cmd, int *tab_clean_exp,
									int clean_exp)
{
	t_clean_cmd *clean_cmd;
	int			index_cmd;
	int			ret_cmd;

	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE, clean_exp, tab_clean_exp);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd);
	ft_printf("index_cmd = %d\n", index_cmd);//DEBUG
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

char		*clean_quote(char *arg)
{
	t_vector	*input;
	t_vector	*output;
	char		*transform_arg;

	input = vct_new();
	output = vct_new();
	vct_addstr(input, arg);
	transform_arg = NULL;
	if (process_clean_quote(input, output) == FAILURE)
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

int			cleaner(t_cmd *cmd)
{
	int		ret_cmd;
	size_t	clean_exp;
	int		*tab_clean_exp;
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		cmd->av[i] = clean_quote(cmd->av[i]);
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
