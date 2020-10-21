#include "minishell_bonus.h"

# define NB_TEST 15

char		*exp_value(char *str)
{
	ft_printf("STR EXP_VALUE = %s\n", str);//DEBUG
	return ("42");
}

static char	*get_good_result(int nb_test)
{
	char	*cmd_line[NB_TEST] = {"toto=haha$tata", //0
			"toto=hahatata", //1
			"toto=haha42", //2
			"toto=haha42", //3
			"toto=hahatata", //4
			"toto=haha'42'", //5
			"toto=haha\"42\"", //6
			"toto=haha\"     42\"", //7
			"toto=hahahey-844242", //8
			"toto=hahahey-8442#hehe42", //9
			"toto=hahaheyho-844242", //10
			"toto=haha42@42", //11
			"toto=42$", //12
			"command not found", //13
			"toto=hahaha'h-a42pouet"};

	return (cmd_line[nb_test]);
}

static char	*get_cmd_line(int nb_test)
{
	char	*cmd_line[NB_TEST] = {"toto=haha'$tata'", //0
			"toto=haha$'tata'", //1
			"toto=haha$tata", //2
			"toto=haha\"$tata\"", //3
			"toto=haha$\"tata\"", //4
			"toto=haha\"'$tata'\"", //5
			"toto=haha'\"'$tata'\"'", //6
			"toto=haha\"     $tata\"", //7
			"toto=haha\"hey-84$tata$titi\"", //8
			"toto=haha\"hey-84$tata#hehe$titi\"", //9
			"toto=haha\"hey\"ho\"-84$tata$titi\"", //10
			"toto=haha$tata@$tata", //11
			"toto=$tata$", //12
			"toto$tata=$tata$", //13
			"toto=haha\"ha'h-a$tata$titi\""};

	return (cmd_line[nb_test]);
}

int			main(void)
{
	size_t		i;
	char		*cmd_line;
	char		*good_result;
	
	i = 0;
	while (i < NB_TEST)
	{
		cmd_line = get_cmd_line(i);
		//ft_printf("cmd_line = %s\n", cmd_line);//DEBUG
		good_result = get_good_result(i);
		cmd_line = clean_quote_exp(cmd_line);
		if (cmd_line == NULL && good_result != NULL)
			ft_printf("mine = NULL		good : %s		nb_test : %d\n", good_result, i);//DEBUG
		else if (ft_strequ(cmd_line, good_result) == FALSE)
			ft_printf("mine : %s		good : %s		nb_test : %d\n", cmd_line, good_result, i);//DEBUG
		ft_printf("\n");//DEBUG
		free(cmd_line);
		i++;
	}
	return (EXIT_SUCCESS);
}
