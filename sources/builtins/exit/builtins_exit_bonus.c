#include "minishell_bonus.h"

void	handle_exit_value(t_vector *vct_av, t_vector *vct_av_cpy, char c)
{
	uint8_t	exit_value;

	safe_vct_cpy(vct_av, vct_av_cpy);
	if (c == C_MINUS || c == C_PLUS)
		safe_vct_addcharat(vct_av, 0, c);
	exit_value = ft_atoi(vct_getstr(vct_av));
	vct_del(&vct_av);
	ms_setenv_int(get_env_list(GET), S_QUESTION_MARK, exit_value, F_OVERWRITE);
	exit_routine(EXIT_NORMAL);
}

int		print_error(t_vector *vct_av, char *av, char c, int flag)
{
	ft_printf("%s\n", EXIT);
	if (vct_getlen(vct_av) == 0 && (flag == (NUM | MINUS_PLUS)))
		print_set_errno(0, ERR_NUM, EXIT, c == C_PLUS ? S_PLUS : S_MINUS);
	else if (flag == NUM || (vct_getlen(vct_av) != 0 &&
				(flag == (NUM | MINUS_PLUS))))
		print_set_errno(0, ERR_NUM, EXIT, av);
	else if (flag == ARG)
	{
		print_set_errno(0, ERR_MANY, EXIT, av);
		return (3);
	}
	vct_del(&vct_av);
	return (2);
}

bool	parse_vct(t_vector *vct_av)
{
	t_vector	*av;
	size_t		count_num;
	size_t		len_before;

	av = safe_vct_new();
	safe_vct_cpy(av, vct_av);
	pop_arg(av, POP_SPACE_TAB);
	safe_vct_cpy(vct_av, av);
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

int		exit_builtin(int ac, char **av, __attribute__((unused)) char **envp)
{
	t_vector	*vct_av;
	char		c;
	int			ret;

	if (ac == 1)
	{
		ft_dprintf(STDERR_FILENO, "%s\n", EXIT);
		exit_routine(EXIT_NORMAL);
	}
	vct_av = safe_vct_new();
	safe_vct_addstr(vct_av, av[1]);
	pop_arg(vct_av, POP_SPACE_TAB);
	c = vct_getfirstchar(vct_av);
	if (c == C_PLUS || c == C_MINUS)
		vct_pop(vct_av);
	ret = check_arg(vct_av, c, av[1], ac);
	if (ret > 2)
	{
		/*si le retour est 3, renvoie Brian doit savoir que 3 veut dire que EXIT
			a fail car trop d'arguments, donc si il recoit 3 et qu'il s'agit de EXIT,
			set a 3 comme ca dans le hub cleaner je vois que ca vient de EXIT et si pas de commande,
			je n'execute pas les autres jobs et donc je resesources/builtins/builtins_history_bonus.cte ensuite la valeur a 2 ?*/
		vct_del(&vct_av);
		return (EXIT_FAIL);
	}
	vct_del(&vct_av);
	return (SUCCESS);
}
