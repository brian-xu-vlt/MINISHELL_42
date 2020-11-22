#include "minishell_bonus.h"

void			print_history(void)
{
	int				i;
	int				lst_size;
	int				end_cursor;
	t_list			*cursor;
	t_le			*le;

	le = get_struct(GET);
	cursor = le->history_cache;
	if (cursor == NULL)
		return ;
	lst_size = ft_lstsize(cursor);
	end_cursor = lst_size - 1;
	while (end_cursor >= 0)
	{
		i = 0;
		while (i < end_cursor)
		{
			cursor = cursor->next;
			i++;
		}
		ft_printf("%5d %s\n", lst_size - end_cursor,
									vct_getstr((t_vector *)cursor->content));
		cursor = le->history_cache;
		end_cursor--;
	}
}

int			history_builtin(int ac, char **av, char **envp)
{
	static const char	*builtin = "history";

	(void)envp;
    if (ac != 1 || ft_strequ(av[0], (char *)builtin) == FALSE)
		return (0);
	else if (DEBUG_MODE != TRUE)
        print_history();
	return (BUILTIN_SUCCESS);
}
