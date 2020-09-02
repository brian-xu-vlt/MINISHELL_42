#include "tester.h"

void	initialize_grammar()
{
// HERE ADD GRAMMAR WORDS (add DATA TYPE at the end of the array)
	static char *grammar[] = {
	
	PLUS,
	MIN,
	TIME,
	DIV,
	MOD,
	STR_WORD

	};

// HERE ADD GRAMMAR TYPE WITHOUT DATA
	static enum e_token_type data_type[] = {

	E_WORD

	};

///////////////////////////////////////////////////////////////////
	g_grammar = grammar;
	g_data_type = data_type;
	g_nb_grammar_type = sizeof(grammar) / sizeof(char *);
	g_nb_data_type = sizeof(data_type) / sizeof(enum e_token_type);
	g_nb_grammar_true_type = g_nb_grammar_type - g_nb_data_type;
}
