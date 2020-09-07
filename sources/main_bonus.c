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

int	main(void)
{
	t_vector	*vct_input;
	t_list		*lexer_list;
	
	vct_input = vct_new();
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
		ft_printf("-- La ligne est [%s] --\n", vct_getstr(vct_input)); // DEBUG
		lexer_list = lexer(vct_input); //fonction qui transforme chaque element en token
		if (lexer_list == NULL /*&& vct_getlen(vct_input) != 0*/)
		{
			vct_del(&vct_input);
			return (EXIT_FAILURE);
		}
		// -> in : vecteur que tu me renvoies
		// -> out : list de token
		//ast = parser(token_list); fonction qui permet de voir si token fonctionne ensemble
		//______exemple : SUJET VERBE COMPLEMENT == FONCTIONNE
		//______exemple : SUJET COMPLEMENT VERBRE == FONCTIONNE PAS
		// -> in : list de token
		// -> out : ast (arbre binaire)
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
	return (EXIT_SUCCESS);
}
