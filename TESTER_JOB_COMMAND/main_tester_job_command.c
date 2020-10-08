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

static void	test_uni_jobs(t_list *job_list, int nb_test)
{
	t_job	*job;
	t_cmd	*cmd;
	size_t	cjob;
	size_t	command;
	
	cjob = 1;
	command = 1;
	while (job_list != NULL)
	{
		job = job_list->content;
		while (job->cmd_lst != NULL)
		{
			cmd = job->cmd_lst->content;
			hub_test(cjob, command, cmd, nb_test);
			job->cmd_lst = job->cmd_lst->next;
			command++;
		}
		command = 1;
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
		lexer_list = test_lexer(cmd_line);
		jobs = get_jobs(lexer_list);
		test_uni_jobs(jobs, i);
		if (jobs == NULL)
		{
			free_list_token(&lexer_list);
			return (EXIT_FAILURE);
		}
		free_list_token(&lexer_list);
		vct_clear(cmd_line);
		i++;
	}
	return (EXIT_SUCCESS);
}
