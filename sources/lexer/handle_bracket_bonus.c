#include "minishell_bonus.h"

int		get_new_type(t_vector *input)
{
	if (vct_getfirstchar(input) != C_QUOTE
			&& vct_getfirstchar(input) != C_SIMPLE_QUOTE)
		return (E_WORD);
	return (vct_getfirstchar(input) == C_QUOTE ? E_QUOTE : E_SIMPLE_QUOTE);
}

char	*handle_bracket(char *str, t_list **token_list)
{
	t_vector	*word;
	t_vector	*input;
	char		c;
	
	word = vct_new();
	input = vct_new();
	vct_addstr(input, str);
	while (vct_getlen(input) > 0)
	{
		//ft_printf("input = %s\n", vct_getstr(input));//DEBUG
		//ft_printf("WORD = %s\n", vct_getstr(word));//DEBUG
		c = vct_getfirstchar(input);
		if (c != '(' && c != ')')
			vct_add(word, c);
		if ((c == '(' || c == ')') && (vct_chr(input, C_QUOTE) != FAILURE
				|| vct_chr(input, C_SIMPLE_QUOTE) != FAILURE))
			vct_add(word, c);
		if ((c == '(' || c == ')') && vct_getlen(word) != 0
				&& vct_chr(input, C_SIMPLE_QUOTE) == FAILURE
				&& vct_chr(input, C_QUOTE) == FAILURE)
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
