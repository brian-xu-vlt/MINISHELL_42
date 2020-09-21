#include "minishell_bonus.h"

void	print_prompt(void)
{
	ft_printf("SHELL > ");
}

void	print_list(t_list *lst)
{
	t_token *token;
	int		i = 1;

	while (lst != NULL)
	{
		token = lst->content;
		if (token != NULL)
			ft_printf("[%d] - token->type = '%d' | token->data = '%s'\n", i++,
				token->type, token->data);
		lst = lst->next;
	}
}

void	read_loop(void)
{
	print_prompt();
	if (vct_readline(vct_input, 0) <= 0)
	{
		vct_del(&vct_input);
		free_list(&lexer_list);
	}
}

int		main(int ac, char **av, char **env)
{
	t_le	*le;

	init_minishell();
	le = get_struct(GET);
	init_env(env);
	(void)ac;
	(void)av;
	while (ft_strncmp(vct_getstr(le->cmd_line), "quit", 5) != 0)
	{
		vct_clear(le->cmd_line);
		if (BONUS_FLAG == TRUE)
		{
			line_editor();
			save_history();
		}
		else
			read_loop();
		test(le->cmp_line);
	

		if (ft_strncmp(vct_getstr(le->cmd_line), "history", 8) == 0)
			print_history();
		}
	exit_routine_le(NULL);
	return (0);
}

int	main(void)
{
	t_vector	*vct_input;
	t_list		*lexer_list;
	
	vct_input = vct_new();
<<<<<<< HEAD
	while (1)
	{
		print_prompt();
		if (vct_readline(vct_input, 0) <= 0)
		{
			/*ici j'utilise vct readline (comme GNL mais avec des vecteurs) car
			il n y a pas encore d'edition de ligne, mais a la place de vct readline
			il faut mettre ta fonction d'edition de ligne (qui utilisera read)
			qui mettra la ligne courante dans vct_input que moi j'utiliserais dans mon lexer*/
			vct_del(&vct_input);
			free_list(&lexer_list);
			return (EXIT_FAILURE);
		}
		//ft_printf("-- La ligne est [%s] --\n", vct_getstr(vct_input)); // DEBUG
=======
	ast = NULL;
		ft_printf("-- La ligne est [%s] --\n", vct_getstr(vct_input)); // DEBUG
>>>>>>> 4f6cc56b27b3a75953de63c74231526eee7d30f9
		lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
		if (lexer_list == NULL /*&& vct_getlen(vct_input) != 0*/)
		{
			free_list(&lexer_list);
			vct_del(&vct_input);
			return (EXIT_FAILURE);
		}
		// -> in : vecteur que tu me renvoies
		// -> out : list de token
		if (parser_token(lexer_list) == FALSE) //fonction qui permet de voir si token fonctionne
		{
			free_list(&lexer_list);
			vct_del(&vct_input);
			return (EXIT_FAILURE);
		}
		//ast = exp_var(ast); fonction qui permet d'expandre les variables $
		// -> in : ast
		// -> out : ast
		//ast = semiantic(ast); fonction qui permet de voir si la phrase a du sens dans le contexte
		//_____exemple : j'ai 32 ans == FONCTIONNE
		//_____exemple : j'en ai 32 == FONCTIONNE PAS (car aucun contexte)
		// -> in : ast
		// -> out : ast
		// struct (a debattre) = interpretor(ast)
		// execution(struct);
//		print_list(lexer_list); // DEBUG
		free_list(&lexer_list);
	}
//	print_list(lexer_list); // DEBUG
	vct_del(&vct_input);
	free_list(&lexer_list);
	return (EXIT_SUCCESS);
}
