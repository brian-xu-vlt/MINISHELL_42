#ifndef TESTER_H
# define TESTER_H

///////////////////////////// HERE DEFINE WORDS /////////////////////////

#define SEPARATOR		";"//0
#define PIPE			"|"//1
#define SIMPLE_QUOTE	"'"//2
#define QUOTE			"\""//3
#define LESS_THAN		"<"//4
#define GREATER_THAN	">"//5
#define	SPACE			" "//6
#define TAB				"\t"//7
#define DOUBLE_GREATER	">>"//8
#define OR				"||"//9
#define AND				"&&"//10
#define STR_WORD		"WORD"//11
#define EXP				"$"//12
#define ASSIGN			"="//13

enum e_token_type
{
	E_SEPARATOR,//0
	E_PIPE,//1
	E_SIMPLE_QUOTE,//2
	E_QUOTE,//3
	E_LESS_THAN,//4
	E_GREATER_THAN,//5
	E_SPACE,//6
	E_TAB,//7
	E_DOUBLE_GREATER,//8
	E_OR,//9
	E_AND,//10
	E_WORD,//11
	E_EXP,//12
	E_ASSIGN//13
};

//////////////////////////////////////////////////////////////////////////


# include "libft.h"
# include "assert.h"
# include "stdbool.h"
# include <unistd.h>
# define TYPE_DELIMITER "#@"

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
