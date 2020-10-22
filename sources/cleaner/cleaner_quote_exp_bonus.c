#include "minishell_bonus.h"

char	*between_nothing(char *str)
{
	char	*good_str;
	t_vector	*vct_good;
	bool		is_exp;
	size_t		i;

	good_str = NULL;
	vct_good = vct_new();
	is_exp = false;
	i = 0;
	ft_printf("BETWEEN_NOTHING\n");//DEBUG
	while (str[i] != '\0')
	{
		if (str[i] != EXP || (str[i] == EXP && i == ft_strlen(str) - 1))
			vct_add(vct_good, str[i]);
		else if (str[i] == EXP)
		{
			i = handle_exp(i, vct_good, str);
			continue ;
		}
		i++;
	}
	good_str = ft_strdup(vct_getstr(vct_good));
	vct_del(&vct_good);
	return (good_str);
}

char	*between_simple(char *str)
{
	char	*good_str;
	size_t	i;
	size_t	end_quote;
	t_vector	*vct_good;
	char		*str_simple;

	ft_printf("BETWEEN_SIMPLE\n");//DEBUG
	good_str = NULL;
	i = 0;
	end_quote = 0;
	str_simple = NULL;
	vct_good = vct_new();
	while (str[i] != '\0')
	{
		if (str[i] == C_SIMPLE_QUOTE)
		{
			end_quote = end_simple(str, i);
			str_simple = handle_simple(str, i, end_quote);
			i = i + end_quote;
			vct_addstr(vct_good, str_simple);
			free(str_simple);
			continue ;
		}
		if (str[i] == EXP)
		{
			i = handle_exp(i, vct_good, str);
			continue ;
		}
		vct_add(vct_good, str[i]);
		i++;
	}
	good_str = ft_strdup(vct_getstr(vct_good));
	vct_del(&vct_good);
	return (good_str);
}

char	*between_double(char *str)
{
	char	*good_str;

	ft_printf("BETWEEN_DOUBLE\n");//DEBUG
	good_str = NULL;
	return (good_str);
}

char	*between_both(char *str)
{
	char	*good_str;

	ft_printf("BETWEEN_BOTH\n");//DEBUG
	good_str = NULL;
	return (good_str);
}
