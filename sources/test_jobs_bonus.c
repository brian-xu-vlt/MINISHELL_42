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

void	debug_jobs(t_list *job_list)
{
	t_job	*job;
	t_cmd	*cmd;
	size_t	i;
	
	i = 1;
	ft_printf("\n");//DEBUG
	while (job_list != NULL)
	{
		job = job_list->content;
		ft_printf("\033[32;01mJOBS %d\033[00m\n", i);
		while (job->cmd_lst != NULL)
		{
			ft_printf("\033[31;01mCOMMAND\033[00m\n");
			cmd = job->cmd_lst->content;
			ft_printf("name = %s\n", cmd->name);
			debug_av(cmd->av, cmd->ac);
			ft_printf("ac = %d\n", cmd->ac);
			ft_printf("fd_string[0] = %s\n", cmd->fd_string[0]);
			ft_printf("fd_string[1] = %s\n", cmd->fd_string[1]);
			ft_printf("fd_string[2] = %s\n", cmd->fd_string[2]);
			ft_printf("condition = %s\n", what_conditon(cmd->condition));
			ft_printf("condition = %d\n\n", cmd->redirection);
			job->cmd_lst = job->cmd_lst->next;
		}
		ft_printf("\n");
		job_list = job_list->next;
		i++;
	}
}

t_list	*test_jobs(t_list *lexer_list)
{
	t_list		*jobs;
	
	jobs = get_jobs(lexer_list);
	if (jobs == NULL)
	{
		free_list_token(&lexer_list);
		return (NULL);
	}
	debug_jobs(jobs);
	return (jobs);
}
