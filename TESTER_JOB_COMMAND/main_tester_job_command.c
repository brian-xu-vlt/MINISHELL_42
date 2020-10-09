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

static int	test_uni_jobs(t_list *job_list, int nb_test)
{
	t_job	*job;
	t_cmd	*cmd;
	size_t	cjob;
	size_t	command;
	t_list	*tmp_cmd_lst;
	
	cjob = 1;
	command = 1;
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			cmd = tmp_cmd_lst->content;
			hub_test(cjob, command, cmd, nb_test);
			tmp_cmd_lst = tmp_cmd_lst->next;
			command++;
		}
		command = 1;
		job_list = job_list->next;
		cjob++;
	}
	return (SUCCESS);
}

int			main(int ac, char **av, char **envp)
{
	t_vector	*cmd_line;
	t_list		*lexer_list;
	t_list		*jobs;
	int			i;
	int			ret_jobs;
	int			ret_lexer;
	t_list		*cpy_jobs;

	(void)ac;
	(void)av;
	(void)envp;
	cmd_line = NULL;
	lexer_list = NULL;
	i = 0;
	jobs = NULL;
	cpy_jobs = NULL;
	ret_jobs = SUCCESS;
	ret_lexer = SUCCESS;
	while (i < NB_TEST)
	{
		ret_jobs = SUCCESS;
		ret_lexer = SUCCESS;
		cmd_line = test_job_command(i);
		lexer_list = test_lexer(cmd_line);
		if (lexer_list == NULL)
		{
			free_list_token(&lexer_list);
			vct_del(&cmd_line);
			return (EXIT_FAILURE);
		}
		jobs = NULL;
		cpy_jobs = NULL;
		if (ret_lexer == SUCCESS)
			jobs = get_jobs(lexer_list);
		cpy_jobs = jobs;
		if (jobs == NULL)	
		{
			ret_jobs = FAILURE;
		}
		if (ret_jobs != FAILURE)
			test_uni_jobs(cpy_jobs, i);
		free_list_token(&lexer_list);
		free_list_job(&jobs);
		vct_clear(cmd_line);
		i++;
		vct_del(&cmd_line);
	}
	return (EXIT_SUCCESS);
}
