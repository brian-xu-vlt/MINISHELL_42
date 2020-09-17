#include "line_editor_bonus.h"

static void	del_history(void *elem_content)
{
	vct_del(&(*elem_content));
}

void		free_history(void)
{
	t_le		*le;

	le = get_env(GET);
	if (le->history_cache == NULL)
		return ;
	ft_lstclear(&le->history_cache, del_history);	
}

void		print_history(void)
{
	int			i;
	int			lst_size;
	int			end_cursor;
	t_list		*cursor;
	t_le		*le;

	le = get_env(GET);
	cursor = le->history_cache;
	if (cursor == NULL)
		return ;
	lst_size = ft_lstsize(cursor);
	i = 0;
	end_cursor = lst_size - 1;
	while (end_cursor >= 0)
	{
		while (i < end_cursor)
		{
			cursor = cursor->next;
			i++;
		}
		ft_printf("%5d %s\n", lst_size - end_cursor,
									vct_getstr((t_vector *)cursor->content)); 
		cursor = le->history_cache;
		end_cursor--;
		i = 0;
	}
}

t_vector	*browse_history(long key)
{
	static int	next_call_elem;
	t_list	 	*cursor;
	t_le		*le;
	int			i;

	le = get_env(GET);
	if (key == RESET)
	{
		if (le->cmd_line_backup != NULL)
			le->cmd_line = le->cmd_line_backup;
		next_call_elem = 0;
		return (NULL);
	}
	i = 0;
	cursor = le->history_cache;
	if (key == K_UP)
	{
		while (cursor->next != NULL &&  i < next_call_elem)
		{
			cursor = cursor->next;
			i++;
		}
		if (cursor->next != NULL)
			next_call_elem++;
	}
	else if (key == K_DOWN && next_call_elem > 0)
	{
		while (cursor->next != NULL &&  i < next_call_elem - 1)
		{
			cursor = cursor->next;
			i++;
		}
		next_call_elem--;
	}
	else
		return (NULL);
	return ((t_vector *)cursor->content);
}

void		call_history(long key)
{
	t_vector	*vct_history_element;
	t_le		*le;

	le = get_env(GET);
	if (le->history_cache == NULL)
		return ;
	if (le->cmd_line_backup == NULL)
		le->cmd_line_backup = le->cmd_line;
	vct_history_element = browse_history(key);
	if (vct_history_element == NULL)
	{
		le->cmd_line = le->cmd_line_backup;
		le->cmd_line_backup = NULL;
	}
	else
		le->cmd_line = vct_history_element;
	le->screen_flag |= HISTORY_REFRESH;
}

void		save_history(void)
{
	t_list		*new_history_element;
	t_le		*le;

	le = get_env(GET);
	if (vct_getlen(le->cmd_line) > 0)
	{
		new_history_element = ft_lstnew(vct_dup(le->cmd_line));
		if (le->history_cache == NULL)
			le->history_cache = new_history_element;
		else
			ft_lstadd_front(&le->history_cache, new_history_element);
	}
	browse_history(RESET);
}
