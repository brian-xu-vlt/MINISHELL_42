#include "minishell_bonus.h"

static void		free_clean_command(t_clean_cmd *clean_cmd, int flag, int clean_exp,

								int *tab_clean_exp)
{
	size_t	i;

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
	t_clean_cmd	*clean_cmd;

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

static int			process_clean_command(t_cmd *cmd, int *tab_clean_exp, int clean_exp)
{
	t_clean_cmd *clean_cmd;
	int			index_cmd;
	int			ret_cmd;
	int			i;
	int			i_exp;

	//ft_printf("PROCESS CLEAN COMMAND\n");//DEBUG
	//ft_printf("CMD->AV[0] = %s\n", cmd->av[0]);//DEBUG
	clean_cmd = init_clean_command();
	if (clean_cmd == NULL)
	{
		free_clean_command(clean_cmd, NOT_ALL_FREE, clean_exp, tab_clean_exp);
		return (FAILURE);
	}
	index_cmd = get_cmd(cmd);
	//ft_printf("index_cmd = %d\n", index_cmd);//DEBUG
	i = 0;
	i_exp = 0;
	while (i < cmd->ac)
	{
		ft_printf("i = %d\n", i);//DEBUG
		ft_printf("i_exp = %d\n", i_exp);//DEBUG
		ft_printf("clean_exp = %d\n", clean_exp);//DEBUG
		if (clean_exp == 0 || (i < clean_exp && i != tab_clean_exp[i_exp]))
		{
			ft_printf("cmd->av[%d] = %s\n", i, cmd->av[i]);//DEBUG
			cmd->av[i] = clean_quote_no_exp(cmd->av[i]);
		}
		if (i > clean_exp)
		{
			cmd->av[i] = clean_quote_no_exp(cmd->av[i]);
		}
		else if (i < clean_exp && i == tab_clean_exp[i_exp])
			i_exp++;
		i++;
	}
	ret_cmd = get_envp_av(cmd, clean_cmd, index_cmd);
	ft_printf("ret_cmd cleaner = %d\n", ret_cmd);//DEBUG
	if (ret_cmd == FAILURE)
	{
		free_clean_command(clean_cmd, ALL_FREE, clean_exp, tab_clean_exp);
		return (FAILURE);
	}
	if (ret_cmd != NO_COMMAND)
		process_redirection(cmd, clean_cmd);
	free_clean_command(clean_cmd, ALL_FREE, clean_exp, tab_clean_exp);
	return (SUCCESS);
}

void		clean_quote(t_cmd *cmd)
{
	size_t	i;
	char	*tmp_av0;

	i = 0;
	tmp_av0 = ft_strdup(cmd->av[0]);
	while (i < (size_t)cmd->ac)
	{
		if (is_clean(i, tmp_av0, cmd->av[i], cmd) == true)
			process_clean_command_quote(cmd, i);
		i++;
	}
	free(tmp_av0);
}

int			cleaner(t_cmd *cmd)
{
	int	ret_cmd;
	size_t	i;
	size_t	clean_exp;
	int		*tab_clean_exp;
	size_t	i_exp;

	i = 0;

	//clean_quote(cmd);
	clean_exp = 0;
	while (i < (size_t)cmd->ac)
	{
		if (ft_strchr(cmd->av[i], EXP) != NULL)
			clean_exp++;
		i++;
	}
	//ft_printf("clean_exp = %d\n", clean_exp);//DEBUG
	i = 0;
	if (clean_exp != 0)
	{
		tab_clean_exp = (int *)malloc(sizeof(int) * clean_exp);
		if (tab_clean_exp == NULL)
			return (FAILURE);
	}
	i_exp = 0;
	while (i < (size_t)cmd->ac)	
	{
		if (ft_strchr(cmd->av[i], EXP) != NULL)
		{
			if (clean_exp != 0)
			{
				tab_clean_exp[i_exp] = i;
				i_exp++;
			}
			cmd->av[i] = clean_quote_exp(cmd->av[i]);
		}
		i++;
	}
	i = 0;
	while (i < clean_exp)
	{
		//ft_printf("tab_clean_exp[%d] = %d\n", i, tab_clean_exp[i]);//DEBUG
		i++;
	}
	ret_cmd = process_clean_command(cmd, tab_clean_exp, clean_exp);
	return (ret_cmd);
}
