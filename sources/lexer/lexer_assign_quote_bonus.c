#include "minishell_bonus.h"

static int	check_quote_simplequote(t_vector *word)
{
	t_vector *cpy_word;

	ft_printf("CHECK QUOTE\n");//DEBUG
	ft_printf("word = %s\n", vct_getstr(word));//DEBUG
	cpy_word = word;
	while (vct_getlen(cpy_word) > 0)
	{
		vct_pop(cpy_word);
	}
	return (SUCCESS);
}

static bool	stop_assign_str(t_vector *input)
{
	t_vector *cpy_input;

	cpy_input = input;
	vct_pop(cpy_input);
	vct_cutfrom(cpy_input, vct_getlen(cpy_input) - 2);
	return (ft_strequ(vct_getstr(cpy_input), OR) == TRUE
				|| ft_strequ(vct_getstr(cpy_input), AND) == TRUE
				|| ft_strequ(vct_getstr(cpy_input), DOUBLE_GREATER) == TRUE ?
				true : false);
				
}

static bool	stop_assign_char(char c)
{
	return (c == C_SEPARATOR || c == C_PIPE || c == C_LESS_THAN
				|| c == C_GREATER_THAN || c == C_SPACE ? true : false);
}

int	handle_assign_quote(t_vector **input, t_vector **word)
{
	int	quote_open;
	int	quote_close;
	int	simple_quote_open;
	int	simple_quote_close;
	int	count_loop;
	t_vector	*cpy_input;
	int	no_error;
	int	ret;

	quote_open = FALSE;
	quote_close = FALSE;
	simple_quote_open = FALSE;
	simple_quote_close = FALSE;
	count_loop = 0;
	vct_add(*word, vct_getfirstchar(*input));	
	vct_pop(*input);
	no_error = FALSE;
	ret = TRUE;
	while (vct_getlen(*input) > 0)
	{
		cpy_input = vct_dup(*input);
		if (count_loop != 0 && (stop_assign_char(vct_getcharat(*input, 1)) == true
				|| stop_assign_str(cpy_input) == true))
		{
			//ft_printf("input = %s\n", vct_getstr(*input));//DEBUG
			//ft_printf("quote_close = %d\n", quote_close);//DEBUG
			//ft_printf("simple_quote_close = %d\n", simple_quote_close);//DEBUG
			//ft_printf("quote_open = %d\n", quote_open);//DEBUG
			//ft_printf("simple_quote_open = %d\n", simple_quote_open);//DEBUG
			vct_add(*word, vct_getfirstchar(*input));
			//ft_printf("first_char = %c\n", vct_getfirstchar(*input));//DEBUG
			if (quote_open == FALSE && vct_getfirstchar(*input) == C_QUOTE)
			{
				//ft_printf("MODIF QUOTE_OPEN\n");//DEBUG
				quote_open = TRUE;	
			}
			else if (quote_open == TRUE && vct_getfirstchar(*input) == C_QUOTE)
			{
				//ft_printf("MODIF QUOTE_OPEN\n");//DEBUG
				quote_open = FALSE;	
			}
			if (simple_quote_open == FALSE && vct_getfirstchar(*input) == C_SIMPLE_QUOTE)
			{
				//ft_printf("MODIF QUOTE_OPEN\n");//DEBUG
				simple_quote_open = TRUE;	
			}
			else if (simple_quote_open == TRUE && vct_getfirstchar(*input) == C_SIMPLE_QUOTE)
			{
				//ft_printf("MODIF QUOTE_OPEN\n");//DEBUG
				simple_quote_open = FALSE;	
			}
			//ft_printf("quote_close AFTER = %d\n", quote_close);//DEBUG
			//ft_printf("simple_quote_close AFTER = %d\n", simple_quote_close);//DEBUG
			//ft_printf("quote_open AFTER = %d\n", quote_open);//DEBUG
			//ft_printf("simple_quote_open AFTER = %d\n", simple_quote_open);//DEBUG
			if (quote_open == FALSE || simple_quote_open == FALSE)
			{	
				no_error = TRUE;
				break ;
			}
			else
			{
				ft_printf("ERROR WHILEEE\n");//DEBUG
				ret = check_quote_simplequote(*word);
				return (FAILURE);
			}
		}	
		if (quote_open == FALSE && vct_getfirstchar(*input) == C_QUOTE)
		{
			quote_open = TRUE;	
		}
		else if (quote_open == TRUE && vct_getfirstchar(*input) == C_QUOTE)
		{
			quote_close = TRUE;
		}
		if (quote_close == TRUE && quote_open == TRUE)
		{
			//ft_printf("PASSE ICI ?\n");//debug
			quote_close = FALSE;
			quote_open = FALSE;
		}
		if (simple_quote_open == FALSE && vct_getfirstchar(*input) == C_SIMPLE_QUOTE)
		{
			simple_quote_open = TRUE;	
		}
		else if (simple_quote_open == TRUE && vct_getfirstchar(*input) == C_SIMPLE_QUOTE)
		{
			simple_quote_close = TRUE;
		}
		if (simple_quote_close == TRUE && simple_quote_open == TRUE)
		{
			simple_quote_close = FALSE;
			simple_quote_open = FALSE;
		}
		count_loop++;
		vct_add(*word, vct_getfirstchar(*input));	
		vct_pop(*input);
	}
	//ft_printf("quote_close END = %d\n", quote_close);//DEBUG
	//ft_printf("simple_quote_close END = %d\n", simple_quote_close);//DEBUG
	//ft_printf("quote_open END = %d\n", quote_open);//DEBUG
	//ft_printf("simple_quote_open END = %d\n", simple_quote_open);//DEBUG
	//ft_printf("NO ERROR = %d\n", no_error);//DEBUG
	if ((no_error == FALSE && (quote_open == TRUE || simple_quote_open == TRUE)) 
			|| (no_error == TRUE && quote_open == TRUE)
			|| (no_error == TRUE && simple_quote_open == TRUE))
	{
		ft_printf("ERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRROR END\n");//DEBUG
		ret = check_quote_simplequote(*word);
		return (FAILURE);
	}
	return (SUCCESS);
}
