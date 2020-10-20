#include "minishell_bonus.h"

char *clean_quote_exp(char *str)
{
	return (str);
}

static enum e_state_quote_no_exp	out(char c)
{
	if (c == C_SIMPLE_QUOTE)
		return (E_IN_SIMPLE_QUOTE);
	if (c == C_QUOTE)
		return (E_IN_DOUBLE_QUOTE);
	return (E_OUT);
}

static enum e_state_quote_no_exp	in_double_quote(char c)
{
	if (c == C_QUOTE)
		return (E_OUT);
	return (E_IN_DOUBLE_QUOTE);
}

static enum e_state_quote_no_exp	in_simple_quote(char c)
{
	if (c == C_SIMPLE_QUOTE)
		return (E_OUT);
	return (E_IN_SIMPLE_QUOTE);
}

char	*clean_quote_no_exp(char *str)
{
	t_vector					*vct_good;
	t_state_quote_no_exp		function_state[] = {in_simple_quote,
													in_double_quote, out};
	enum e_state_quote_no_exp	state;
	size_t						i;

	vct_good = vct_new();
	state = E_OUT;
	i = 0;
	while (str[i] != '\0')
	{
		state = function_state[state](str[i]);
		vct_add(vct_good, str[i]);
		i++;
	}
	str = vct_getstr(vct_good);
	ft_printf("str = %s\n", str);//DEBUG
	return (str);
}

void	clean_quote(t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)cmd->ac)
	{
		if (ft_strchr(cmd->av[i], EXP) == NULL)
			cmd->av[i] = clean_quote_no_exp(cmd->av[i]);
		else
			cmd->av[i] = clean_quote_exp(cmd->av[i]);
		i++;
	}
}

int	cleaner(t_cmd *cmd)
{
	clean_quote(cmd);
}
