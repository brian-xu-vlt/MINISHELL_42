#include "minishell_bonus.h"

# define NB_TEST 5

static char	*get_good_result(int nb_test)
{
	char	*cmd_line[NB_TEST] = {"\"hello\"=\"h\"ah\"a\"", //0
			"'ca'va=ouais && ha'ha'he", //1
			"export hey='ha'h'e'h't'h", //2
			"'hey'ca'va=ha\"ha\"tropgen'i'al", //3
			"\"hello comment ca va\" trop bien ouais"}; //4

	return (cmd_line[nb_test]);
}

static char	*get_cmd_line(int nb_test)
{
	char	*cmd_line[NB_TEST] = {"'\"he'll'o\"=\"h\"ah\"'a'\"'", //0
			"\"'ca'\"\"va\"=ouais && \"ha'ha'he\"", //1
			"export hey=\"'ha'h'e'h't'h\"", //2
			"\"'hey'ca'\"va\"\"'=''ha\"ha\"'trop''\"\"\"gen'i'al\"", //3
			"'\"hello 'comment' ca va\"' \"\"'trop bien' \"ouais\"\"\""}; //4

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
		cmd_line = clean_quote_no_exp(cmd_line);
		if (ft_strequ(cmd_line, good_result) == FALSE)
			ft_printf("mine : %s	good : %s		nb_test : %d\n", cmd_line, good_result, i);//DEBUG
		i++;
	}
	return (EXIT_SUCCESS);
}
