#include "line_editor_bonus.h"

static t_vector	*browse_history(long key)
{
	static t_list	*next_call_elem;
	t_list			*cursor;

	cursor = get_struct(GET)->history_cache;
	if (key == RESET)
	{
		next_call_elem = get_struct(GET)->history_cache;
		return (NULL);
	}
	else if (key == K_DOWN && next_call_elem == get_struct(GET)->history_cache)
		return (NULL);
	if (key == K_UP)
	{
		while (cursor != NULL && cursor != next_call_elem)
			cursor = cursor->next;
		next_call_elem = (cursor->next != NULL) ? cursor->next : cursor;
	}
	else if (key == K_DOWN)
	{
		while (cursor != NULL && cursor->next != next_call_elem)
			cursor = cursor->next;
		next_call_elem = cursor;
	}
	return ((t_vector *)cursor->content);
}

static void		backup_cmdline(t_le *le)
{
	if (le != NULL && le->cmd_line_backup == NULL && le->cmd_line != NULL)
	{
		le->cmd_line_backup = vct_strdup(le->cmd_line);
		if (le->cmd_line_backup == NULL)
			exit_routine_le(ERR_MALLOC);
	}
}

void			call_history(long key)
{
	t_vector		*vct_history_element;
	t_le			*le;

	le = NULL;
	le = get_struct(GET);
	if (le != NULL && le->history_cache != NULL)
	{
		backup_cmdline(le);
		vct_history_element = browse_history(key);
		if (vct_history_element != NULL)
			vct_cpy(le->cmd_line, vct_history_element);
		else
		{
			vct_clear(le->cmd_line);
			vct_pushstr(le->cmd_line, le->cmd_line_backup);
			free(le->cmd_line_backup);
			le->cmd_line_backup = NULL;
		}
		le->screen_flag |= FULL_REFRESH | HISTORY_REFRESH;
	}
}

void			save_history(void)
{
	t_list			*new_history_element;
	t_le			*le;

	le = NULL;
	le = get_struct(GET);
	if (le != NULL && vct_getlen(le->cmd_line) > 0)
	{
		new_history_element = ft_lstnew(vct_dup(le->cmd_line));
		if (new_history_element == NULL)
			exit_routine_le(ERR_MALLOC);
		if (le->history_cache == NULL)
			le->history_cache = new_history_element;
		else
			ft_lstadd_front(&le->history_cache, new_history_element);
	}
	browse_history(RESET);
}
