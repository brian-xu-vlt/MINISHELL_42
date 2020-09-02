#ifndef TESTER_H
# define TESTER_H

///////////////////////////// HERE DEFINE WORDS /////////////////////////

#define PLUS "+"
#define MIN "-"
#define TIME "*"
#define DIV "/"
#define MOD "%"
#define STR_WORD "WORD"

enum e_token_type
{
	E_PLUS,
	E_MIN,
	E_TIME,
	E_DIV,
	E_MOD,
	E_WORD
};

//////////////////////////////////////////////////////////////////////////


# include "libft.h"
# include "assert.h"
# include "stdbool.h"
# include <unistd.h>
# define TYPE_DELIMITER ";="

typedef t_list	*(*t_lex)(t_vector *);

extern char		**g_grammar;
extern enum		e_token_type *g_data_type;
extern size_t	g_nb_grammar_type;
extern size_t	g_nb_data_type;
extern size_t	g_nb_grammar_true_type;
extern t_lex	g_lexer;

typedef struct s_token
{
	char				*data;
	enum e_token_type	type;
}				t_token;


t_list	*lexer(t_vector	*input);
int		tester(char *input, char *expected);
void	initialize_grammar(void);
void	print_error(char *input, t_list *expected, t_list *list);
bool	is_data_type(enum e_token_type type);

#endif
