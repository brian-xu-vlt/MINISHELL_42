#include "minishell_bonus.h"

static bool	is_numeric(t_vector *av)
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

static bool	parse_vct(t_vector *vct_av)
{
	size_t	index_space;
	size_t	index_tab;
	size_t	len;
	t_vector	*av;
	size_t		count_num;
	size_t		len_before;

	av = vct_new();
	count_num = 0;
	vct_cpy(av, vct_av);
	while (vct_getlen(av) > 0 && (vct_getfirstchar(av) == C_SPACE ||
			vct_getfirstchar(av) == C_TAB))
		vct_pop(av);
	vct_cpy(vct_av, av);
	len_before = vct_getlen(vct_av);
	while (vct_getlen(av) > 0 && ft_isdigit(vct_getfirstchar(av)) == true)
	{
		vct_pop(av);
		count_num++;
	}
	vct_cutfrom(vct_av, len_before - count_num);
	len = vct_getlen(av);
	index_space = vct_clen(av, C_SPACE) ;
	index_tab = vct_clen(av, C_TAB);
	if (index_tab > index_space)
		vct_cutfrom(av, len - (len - index_space));
	else if (index_space > index_tab)
		vct_cutfrom(av, len - (len - index_tab));
	while (vct_getlen(av) > 0)
	{
		if (vct_getfirstchar(av) != C_SPACE && vct_getfirstchar(av) != C_TAB)
			return (false);
		vct_pop(av);
	}
	return (true);
}

static bool	is_to_long(t_vector *av, char c)
{
	if ((c == C_MINUS || c == C_PLUS) && vct_getlen(av) > LEN_MIN_LONG)
		return (false);
	else if (c != C_MINUS && c != C_PLUS &&vct_getlen(av) > LEN_PLUS_LONG)
		return (false);
	if (c == C_PLUS)
		vct_pop(av);
	ft_printf("av = %s\n", vct_getstr(av));//DEBUG

	return (true);
}

int	exit_builtin(int ac, char **av, char **envp)
{
	int	exit_value;
	t_vector	*vct_av;
	t_vector	*vct_av_cpy;
	bool			num_arg;
	char		c;
	bool		ret_parser;
	bool		ret_to_long;

	ft_printf("EXEC BUILTIN\n"); //DEBUG
	(void)envp;
	exit_value = 0;
	if (ac == 1)
	{
		ft_printf("%s\n", EXIT);
		ft_printf("\n");//DEBUG
		//exit(get_env_value_int(get_env_list(GET), S_QUESTION_MARK));
		return (EXIT_FAIL);
	}
	vct_av = vct_new();
	vct_addstr(vct_av, av[1]);
	while (vct_getlen(vct_av) > 0 && (vct_getfirstchar(vct_av) == C_SPACE ||
			vct_getfirstchar(vct_av) == C_TAB))
		vct_pop(vct_av);
	c = vct_getfirstchar(vct_av);
	if (c == C_PLUS || c == C_MINUS)
		vct_pop(vct_av);
	vct_av_cpy = vct_new();
	vct_cpy(vct_av_cpy, vct_av);
	num_arg = is_numeric(vct_av_cpy);
	if (num_arg == false || vct_getlen(vct_av) == 0)
	{
		ft_printf("vct_ac = %s\n", vct_getstr(vct_av));//DEBUG
		ft_printf("%s\n", EXIT);
		if (vct_getlen(vct_av) != 0)
			print_set_errno(0, "numeric argument required", EXIT, av[1]);
		else
			print_set_errno(0, "numeric argument required", EXIT,
								c == C_PLUS ? S_PLUS : S_MINUS);
		ft_printf("\n");//DEBUG
		return (EXIT_FAIL);
		//exit(2);	
	}
	ret_parser = parse_vct(vct_av);
	ft_printf("vct_av AFTER PARSE = [%s]\n", vct_getstr(vct_av));//DEBUG
	if (ret_parser == false)
	{
		ft_printf("%s\n", EXIT);
		print_set_errno(0, "numeric argument required", EXIT,
							av[1]);
		ft_printf("\n");//DEBUG
		return (EXIT_FAIL);
		//exit(2);	

	}
	ft_printf("c = %c\n", c);//DEBUG
	if (c == C_MINUS || c == C_PLUS)
		vct_addcharat(vct_av, 0, c);
	ft_printf("vct_av AFTER ADD = [%s]\n", vct_getstr(vct_av));//DEBUG
	ret_to_long = is_to_long(vct_av, c);
	ft_printf("ret_to_long = %d\n", ret_to_long);//DEBUG
	ft_printf("\n");//DEBUG
	//exit(exit_value);
	return (SUCCESS);
}
	
	
	/*const char	*builtin = "exit";

	(void)envp;
	if (ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	if (ac == 1)
		exit_routine_le("exit");
	return (SUCCESS);*/
