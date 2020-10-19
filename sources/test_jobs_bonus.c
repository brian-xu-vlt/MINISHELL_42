#include "minishell_bonus.h"

static void	debug_av(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		ft_printf("av[%d] = %s\n", i, av[i]);
		i++;	
	}
}

static char	*what_conditon(int type)
{
	if (type == E_NONE)
		return ("E_NONE");
	else if (type == E_NOT_OR)
		return ("E_NOT_OR");
	return ("E_YES_AND");
}

static void	debug_tab_exp(size_t *tab_exp, int count_exp)
{
	int	i;

	i = 0;
	while (i < count_exp)
	{
		ft_printf("tab_exp[%d] = %d\n", i, tab_exp[i]);
		i++;	
	}
}

static void	debug_tab_assign(size_t *tab_assign, int count_assign)
{
	int	i;

	i = 0;
	while (i < count_assign)
	{
		ft_printf("tab_assign[%d] = %d\n", i, tab_assign[i]);
		i++;	
	}
}

void	debug_jobs(t_list *job_list)
{
	t_job	*job;
	t_cmd	*cmd;
	size_t	cjob;
	size_t	command;
	t_list	*tmp_cmd_lst;
	
	cjob = 1;
	command = 1;
	ft_printf("\n");//DEBUG
	while (job_list != NULL)
	{
		job = job_list->content;
		ft_printf("\033[32;01mJOBS %d\033[00m\n", cjob);
		ft_printf("nb_cmd = %d\n", job->nb_cmd);
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			ft_printf("\033[31;01mCOMMAND %d\033[00m\n", command);
			cmd = tmp_cmd_lst->content;
			ft_printf("name = %s\n", cmd->name);
			debug_av(cmd->av, cmd->ac);
			ft_printf("ac = %d\n", cmd->ac);
			ft_printf("fd_string[0] = %s\n", cmd->fd_string[0]);
			ft_printf("fd_string[1] = %s\n", cmd->fd_string[1]);
			ft_printf("fd_string[2] = %s\n", cmd->fd_string[2]);
			ft_printf("condition = %s\n", what_conditon(cmd->condition));
			ft_printf("redirection = %d\n", cmd->redirection);
			ft_printf("count_assign = %d\n", cmd->count_assign);
			ft_printf("count_exp = %d\n", cmd->count_exp);
			debug_tab_assign(cmd->tab_assign, cmd->count_assign);
			debug_tab_exp(cmd->tab_exp, cmd->count_exp);
			ft_printf("\n");//DEBUG
			tmp_cmd_lst = tmp_cmd_lst->next;
			command++;
		}
		command = 1;
		ft_printf("\n");
		job_list = job_list->next;
		cjob++;
	}
}

t_list	*test_jobs(t_list *lexer_list)
{
	t_list		*jobs;
	
	jobs = get_jobs(lexer_list);
	if (jobs == NULL)
		return (NULL);
	debug_jobs(jobs);
	return (jobs);
}
