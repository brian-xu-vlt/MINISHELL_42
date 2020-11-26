#include "minishell_bonus.h"

static bool parse_backslash(t_vector *input, t_vector *word, bool is_quoting)
{
	const char c = vct_getfirstchar(input);
	const char c_next = vct_getcharat(input, 1);

	if (c != '\\')
		return (false);
	if ((is_quoting == true && (c_next == '$' || c_next == '\\' || c_next == '\"'))
			|| is_quoting == false)
	{
		if (is_quoting == true)
		{
		//	ft_printf("IS QUOTING\n");//DEBUG
		//	ft_printf("word = %s\n", vct_getstr(word));
		//	ft_printf("c HAUT = %c\n", c);
		//	ft_printf("input = %s\n", vct_getstr(input));
			vct_add(word, c);
			vct_pop(input);
		//	ft_printf("word AFTER = %s\n", vct_getstr(word));
			//ft_printf("input AFTER = %s\n", vct_getstr(input));
		}
		return (true);
	}
	return (false);
}

int handle_assign_quote(t_vector *input, t_vector *word)
{
	char c;
	bool quote_state;
	bool dquote_state;
	int	ret_parse;

//	ft_printf("input = %s\n\n\n", vct_getstr(input));//DEBUG)
	quote_state = false;
	dquote_state = false;
	while (vct_getlen(input) > 0)
	{
		ret_parse = true;
		c = vct_getfirstchar(input);
		if (c == C_SIMPLE_QUOTE)
			quote_state = !quote_state;
		else if (c == C_QUOTE && quote_state == false)
			dquote_state = !dquote_state;
		//ft_printf("c = %c\n", c);//DEBUYG
		//ft_printf("quote_state = %d\n", quote_state);//DEBUYG
		//ft_printf("dquote_state = %d\n", dquote_state);//DEBUYG
		if (quote_state == false)
		{
			ret_parse = parse_backslash(input, word, dquote_state);
			if (ret_parse == false)
			{
				if (dquote_state == false && is_end(input) == true)
					break;
			}
			else if (ret_parse == true && vct_getlen(input) != 1 && dquote_state == 1 && quote_state == 0)
			{
				//ft_printf("coucou1\n");//DEBUG
				continue ;

			}
			else if (ret_parse == true && vct_getlen(input) != 1 && dquote_state == 0 && quote_state == 1)
			{
				//ft_printf("coucou2\n");//DEBUG
				continue ;
			}
			else if (ret_parse == true && vct_getlen(input) == 1 && dquote_state != 1)
			{
				print_set_errno(0, ERR_NEWLINE, NULL, NULL);
				ms_setenv_int(get_env_list(GET), "?", 2, F_OVERWRITE);
				return (FAILURE);
			}
		}
		c = vct_getfirstchar(input);
		vct_add(word, c);
		vct_pop(input);
	}
	//ft_printf("word = %s\n", vct_getstr(word));//DEBUG)
	return (SUCCESS);
}
