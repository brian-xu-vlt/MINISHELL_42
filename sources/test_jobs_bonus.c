#include "minishell_bonus.h"

static void	debug_av(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		ft_printf("av[%d] = %s\n", av[0]);
		i++;	
	}
}

void	debug_jobs(t_list *job_list)
{
	t_job	*job;
	t_cmd	*cmd;
	size_t	i;
	
	i = 1;
	while (job_list != NULL)
	{
		job = job_list->content;
		ft_printf("\033[32;01mJOBS %d\033[00m\n", i);
		ft_printf("retour job = %d\n", job->ret);
		while (job->cmd_lst != NULL)
		{
			ft_printf("\n\033[31;01mCOMMAND\033[00m\n");
			cmd = job->cmd_lst->content;
			ft_printf("name = %s\n", cmd->name);
			debug_av(cmd->av, cmd->ac);
			ft_printf("ac = %d\n", cmd->ac);
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
