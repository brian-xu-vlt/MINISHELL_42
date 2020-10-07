#include "minishell_bonus.h"

#define NB_TEST	1

static t_vector	*test_job_command(int nb_test)
{
	char	*test[NB_TEST] = {"ls | cat -e && echo ; cat -e hey > prout"};
	t_vector	*vct_test;

	vct_test = vct_new();
	vct_addstr(vct_test, test[nb_test]);
	return (vct_test);
}

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

static void	test_uni_jobs(t_list *job_list, int nb_test)
{
	t_job	*job;
	t_cmd	*cmd;
	size_t	cjob;
	size_t	command;
	
	cjob = 1;
	command = 1;
	ft_printf("\n");//DEBUG
	while (job_list != NULL)
	{
		job = job_list->content;
		ft_printf("\033[32;01mJOBS %d\033[00m\n", cjob);
		while (job->cmd_lst != NULL)
		{
			ft_printf("\033[31;01mCOMMAND %d\033[00m\n", command);
			cmd = job->cmd_lst->content;
			ft_printf("name = %s\n", cmd->name);
			debug_av(cmd->av, cmd->ac);
			ft_printf("ac = %d\n", cmd->ac);
			ft_printf("fd_string[0] = %s\n", cmd->fd_string[0]);
			ft_printf("fd_string[1] = %s\n", cmd->fd_string[1]);
			ft_printf("fd_string[2] = %s\n", cmd->fd_string[2]);
			ft_printf("condition = %s\n", what_conditon(cmd->condition));
			ft_printf("redirection = %d\n\n", cmd->redirection);
			job->cmd_lst = job->cmd_lst->next;
			command++;
		}
		command = 1;
		ft_printf("\n");
		job_list = job_list->next;
		cjob++;
	}
}

int			main(int ac, char **av, char **envp)
{
	t_vector	*cmd_line;
	t_list		*lexer_list;
	t_list		*jobs;
	int			i;

	(void)ac;
	(void)av;
	(void)envp;
	cmd_line = vct_new();
	lexer_list = NULL;
	i = 0;
	while (i < NB_TEST)
	{
		cmd_line = test_job_command(i);
		ft_printf("$>%s\n", vct_getstr(cmd_line));//DEBUGA
		lexer_list = test_lexer(cmd_line);
		jobs = get_jobs(lexer_list);
		test_uni_jobs(jobs, i);
		if (jobs == NULL)
		{
			ft_printf("JOBS == NULL ?\n");//DEBUG
			free_list_token(&lexer_list);
			return (EXIT_FAILURE);
		}
		free_list_token(&lexer_list);
		vct_clear(cmd_line);
		i++;
	}
	return (EXIT_SUCCESS);
}
