#include "minishell_bonus.h"

char	*between_nothing(char *str)
{
	char	*good_str;
	t_vector	*vct_good;
	t_vector	*vct_exp;
	t_vector	*vct_value;
	bool		is_exp;
	size_t		i;
	size_t		tmp_i;

	ft_printf("BETWEEN_NOTHING\n");//DEBUG
	ft_printf("STR = %s\n", str);//DEBUG
	good_str = NULL;
	vct_good = vct_new();
	vct_exp = vct_new();
	vct_value = vct_new();
	is_exp = false;
	i = 0;
	tmp_i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != EXP || (str[i] == EXP && i == ft_strlen(str) - 1))
			vct_add(vct_good, str[i]);
		else if (str[i] == EXP)
		{
			tmp_i = handle_exp(str + i + 1);
			ft_printf("STR + I = %s\n", str + i + 1);//DEBUG
			ft_printf("TMP I = %d\n", tmp_i);//DEBUG
			vct_addstr(vct_exp, str + i + 1);
			ft_printf("VCT_EXP = %s\n", vct_getstr(vct_exp));//DEBUG
			//UTILISER VCT_CUTFROM (VCT_EXP, FTSTRLEN(VCT_EXP) - TMP1)
		}
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
