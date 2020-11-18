#include "minishell_bonus.h"


int	print_error(t_vector *vct_av, char *av, char c, int flag,
							t_vector *vct_av_cpy)
{
	ft_printf("%s\n", EXIT);
	if (vct_getlen(vct_av) == 0 && (flag == (NUM | MINUS_PLUS)))
		print_set_errno(0, "numeric argument required", EXIT,
							c == C_PLUS ? S_PLUS : S_MINUS);
	else if (flag == NUM || (vct_getlen(vct_av) != 0 &&
				(flag == (NUM | MINUS_PLUS))))
		print_set_errno(0, "numeric argument required", EXIT, av);
	else if (flag == ARG)
		print_set_errno(0, "too many arguments", EXIT, av);
	vct_del(&vct_av);
	vct_del(&vct_av_cpy);
	return (2);
}

bool	parse_vct(t_vector *vct_av)
{
	t_vector	*av;
	size_t		count_num;
	size_t		len_before;

	av = vct_new();
	vct_cpy(av, vct_av);
	pop_arg(av, POP_SPACE_TAB);
	vct_cpy(vct_av, av);
	len_before = vct_getlen(vct_av);
	count_num = pop_arg(av, COUNT_NUM);
	cut_arg(vct_av, len_before, count_num, av);
	while (vct_getlen(av) > 0)
	{
		if (vct_getfirstchar(av) != C_SPACE && vct_getfirstchar(av) != C_TAB)
		{
			vct_del(&av);
			return (false);
		}
		vct_pop(av);
	}
	vct_del(&av);
	return (true);
}

int	exit_builtin(int ac, char **av, char **envp)
{
	t_vector	*vct_av;
	t_vector	*vct_av_cpy;
	char		c;

	(void)envp;
	if (ac == 1)
	{
		ft_printf("%s\n", EXIT);
		exit(get_env_value_int(get_env_list(GET), S_QUESTION_MARK));
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
	if (check_arg(vct_av_cpy, vct_av, c, av[1], ac) == 2)
		return (EXIT_FAIL);
	return (SUCCESS);
}
