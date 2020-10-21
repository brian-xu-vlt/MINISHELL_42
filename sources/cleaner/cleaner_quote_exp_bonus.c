#include "minishell_bonus.h"

char	*between_nothing(char *str)
{
	char	*good_str;
	t_vector	*vct_good;
	t_vector	*vct_exp;
	t_vector	*vct_value;
	bool		is_exp;
	size_t		i;

	ft_printf("BETWEEN_NOTHING\n");//DEBUG
	good_str = NULL;
	vct_good = vct_new();
	vct_exp = vct_new();
	vct_value = vct_new();
	is_exp = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != EXP)
			vct_add(vct_good, str[i]);
		/*if (str[i] == EXP)
		{
			
		}*/
		i++;
	}
	good_str = ft_strdup(vct_getstr(vct_good));
	vct_del(&vct_good);
	vct_del(&vct_exp);
	vct_del(&vct_value);
	return (good_str);
}

char	*between_simple(char *str)
{
	char	*good_str;

	ft_printf("BETWEEN_SIMPLE\n");//DEBUG
	good_str = NULL;
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
