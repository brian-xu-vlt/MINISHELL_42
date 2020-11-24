#include "minishell_bonus.h"

bool		is_numeric(t_vector *av)
{
	char	c;

	while (vct_getlen(av) > 0)
	{
		c = vct_getfirstchar(av);
		if (ft_isdigit(c) == false && c != C_SPACE && c != C_TAB)
			return (false);
		vct_pop(av);
	}
	return (true);
}

void		cut_arg(t_vector *vct_av, size_t len_before, size_t count_num,
						t_vector *av)
{
	size_t	index_space;
	size_t	index_tab;
	size_t	len;

	vct_cutfrom(vct_av, len_before - count_num);
	len = vct_getlen(av);
	index_space = vct_clen(av, C_SPACE);
	index_tab = vct_clen(av, C_TAB);
	if (index_tab > index_space)
		vct_cutfrom(av, len - (len - index_space));
	else if (index_space > index_tab)
		vct_cutfrom(av, len - (len - index_tab));
}

size_t		pop_arg(t_vector *av, int flag)
{
	size_t count_num;

	count_num = 0;
	if (flag == POP_SPACE_TAB)
	{
		while (vct_getlen(av) > 0 && (vct_getfirstchar(av) == C_SPACE ||
				vct_getfirstchar(av) == C_TAB))
			vct_pop(av);
	}
	if (flag == COUNT_NUM)
	{
		while (vct_getlen(av) > 0 && ft_isdigit(vct_getfirstchar(av)) == true)
		{
			vct_pop(av);
			count_num++;
		}
		return (count_num);
	}
	return (SUCCESS);
}

bool		is_long(t_vector *av, char c)
{
	static char	*ref_plus = "9223372036854775807";
	static char	*ref_minus = "9223372036854775808";
	size_t		i;
	char		first_c;
	char		*str;

	i = 0;
	if (vct_getlen(av) > 19 && vct_getfirstchar(av) != '0')
		return (true);
	else if (vct_getlen(av) < 19)
		return (false);
	str = c == C_MINUS ? ref_minus : ref_plus;
	while (vct_getlen(av) > 0 && str[i] != '\0')
	{
		first_c = vct_getfirstchar(av);
		if (i == 0 && first_c < '9')
			return (false);
		if (first_c == '0' && str[i] != '0')
			return (false);
		if (first_c > str[i])
			return (true);
		i++;
		vct_pop(av);
	}
	return (false);
}

int			check_arg(t_vector *vct_av, char c, char *av, int ac)
{
	t_vector	*vct_av_cpy;
	bool		num_arg;
	bool		ret_parser;
	bool		ret_long;

	vct_av_cpy = vct_new();
	vct_cpy(vct_av_cpy, vct_av);
	num_arg = is_numeric(vct_av_cpy);
	if (num_arg == false || vct_getlen(vct_av) == 0)
	{
		ms_setenv_int(get_env_list(GET), "?",
						print_error(vct_av, av, c, MINUS_PLUS | NUM),
													F_OVERWRITE);
		exit_routine_le(NORMAL_EXIT);
	}
	ret_parser = parse_vct(vct_av);
	if (ret_parser == false)
	{
		ms_setenv_int(get_env_list(GET), "?", print_error(vct_av, av, c, NUM),
						F_OVERWRITE);
		exit_routine_le(NORMAL_EXIT);
	}
	vct_cpy(vct_av_cpy, vct_av);
	ret_long = is_long(vct_av, c);
	if (ret_long == true)
	{
		ms_setenv_int(get_env_list(GET), "?", print_error(vct_av, av, c, NUM),
						F_OVERWRITE);
		exit_routine_le(NORMAL_EXIT);
	}
	if (ret_long == false && ac > 2)
	{
		vct_del(&vct_av_cpy);
		return (print_error(vct_av, NULL, c, ARG));
	}
	handle_exit_value(vct_av, vct_av_cpy, c);
	return (SUCCESS);
}
