#include "tester.h"

void	initialize_grammar()
{
// HERE ADD GRAMMAR WORDS (add DATA TYPE at the end of the array)
	static char *grammar[] = {
	
	SEPARATOR,
	PIPE,
	SIMPLE_QUOTE,
	QUOTE,
	LESS_THAN,
	GREATER_THAN,
	SPACE,
	TAB,
	DOUBLE_GREATER,
	OR,
	AND,
	STR_WORD,
	EXP,
	ASSIGN
	};

// HERE ADD GRAMMAR TYPE WITH DATA
	static enum e_token_type data_type[] = {

	E_WORD,//11
	E_EXP,//12
	E_ASSIGN//13

	};

///////////////////////////////////////////////////////////////////
	g_grammar = grammar;
	g_data_type = data_type;
	g_nb_grammar_type = sizeof(grammar) / sizeof(char *);
	g_nb_data_type = sizeof(data_type) / sizeof(enum e_token_type);
	g_nb_grammar_true_type = g_nb_grammar_type - g_nb_data_type;
}
