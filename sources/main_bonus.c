#include "minishell_bonus.h"

static void	print_prompt(void)
{
	ft_printf("SHELL > ");
}

static void	read_loop(t_vector *cmd_line)
{
	print_prompt();
	vct_readline(cmd_line, 0);
}

static void	usage(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac != 1)
	{
		ft_printf("Usage: Minishell does not take any argument\n");
		exit (FAILURE);
	}
}

static t_list	*process_minishell(t_vector *cmd_line)
{
	t_list		*lexer_list;
	t_list		*jobs;
	int			ret_parser;	

	lexer_list = NULL;
	jobs = NULL;
	ret_parser = SUCCESS;
	lexer_list = test_lexer(cmd_line);
	if (lexer_list != NULL)
	{
		ret_parser = test_parser(lexer_list);
		if (ret_parser != FALSE)
			jobs = test_jobs(lexer_list);
		if (jobs == NULL)
			free_list_job(&jobs);
	}
	free_list_token(&lexer_list);
	return (jobs);
}

int	waiter(t_list *job_list)
{
	t_job	*job;
	t_list	*tmp_cmd_lst;
	t_cmd	*cmd;
	
	while (job_list != NULL)
	{
		job = job_list->content;
		tmp_cmd_lst = job->cmd_lst;
		while (tmp_cmd_lst != NULL)
		{
			cmd = tmp_cmd_lst->content;
			test_cleaner(cmd);
			tmp_cmd_lst = tmp_cmd_lst->next;
		}
		job_list = job_list->next;
	}
}

int			main(int ac, char **av, char **envp)
{
	t_vector	*cmd_line;
	t_list		*jobs;

	usage(ac, av);
	init_env(envp);
	cmd_line = vct_new();
	if (cmd_line == NULL)
		exit_routine_le(ERR_MALLOC);
	init_line_editor(cmd_line);
	jobs = NULL;
	while (1)
	{
		if (BONUS_FLAG == TRUE)
		{
			line_editor();
			save_history();
		}
		else
			read_loop(cmd_line);
		if (ft_strncmp(vct_getstr(cmd_line), "exit", 5) == 0)
			break ;
		if (test_env(cmd_line) == FAILURE)
		{
			exit_routine_le(NULL);
			free_list_job(&jobs);
			return (EXIT_FAILURE);//ERREUR
		}
		jobs = process_minishell(cmd_line);
		if (jobs != NULL)
			waiter(jobs);
		vct_clear(cmd_line);
		free_list_job(&jobs);
	}
	exit_routine_le(NULL);
	free_list_job(&jobs);
	return (EXIT_SUCCESS);
}
