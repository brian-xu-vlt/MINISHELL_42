#include "minishell_bonus.h"

char	*handle_bracket(t_token *token, char *str, t_list **token_list)
{
	t_vector	*word;
	t_vector	*input;
	char		c;
	
	word = vct_new();
	input = vct_new();
	vct_addstr(input, str);
	while (vct_getlen(input) > 0)
	{
		c = vct_getfirstchar(input);
		if (c != '(' && c != ')')
			vct_add(word, c);
		if ((c == '(' || c == ')') && vct_getlen(word) != 0)
		{
			extract_token(token_list, vct_getstr(word), E_WORD);
			vct_clear(word);
		}
		if ((c == '(' || c == ')') && vct_getlen(word) == 0)
		{
			return (vct_getstr(input));
		}
		vct_pop(input);
	}
	return (NULL);
}
