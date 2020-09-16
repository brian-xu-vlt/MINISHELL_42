#include "line_editor_bonus.h"

t_vector	*browse_history(long key)
{
	static int	next_call_elem;
	t_list	 	*return_element;
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
	return_element = le->history_cache;
	if (key == K_UP)
	{
		while (return_element->next != NULL &&  i < next_call_elem)
		{
			return_element = return_element->next;
			i++;
		}
		if (return_element->next != NULL)
			next_call_elem++;
	}
	else if (key == K_DOWN && next_call_elem > 0)
	{
		while (return_element->next != NULL &&  i < next_call_elem - 1)
		{
			return_element = return_element->next;
			i++;
		}
		next_call_elem--;
	}
	else
		return (NULL);
	return ((t_vector *)return_element->content);
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
	debug_print_flag(vct_getstr(le->cmd_line));
		new_history_element = ft_lstnew(vct_dup(le->cmd_line));
		if (le->history_cache == NULL)
			le->history_cache = new_history_element;
		else
			ft_lstadd_front(&le->history_cache, new_history_element);
	}
	browse_history(RESET);
}
