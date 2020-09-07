#include "minishell_bonus.h"

int	handle_quote(t_vector *input, t_list **token_list, int ret)
{
	t_vector	*vct;
	size_t		len;
	t_vector	*tmp;
	size_t		len_tmp;
	int			ret_extract;

	ret_extract = SUCCESS;
	vct = vct_cdup(input, ret == N_SIMPLE_QUOTE ? C_SIMPLE_QUOTE
			: C_QUOTE);
	ft_printf("vct = %s\n", vct_getstr(vct));//DEBUG
	if (vct_equ(input, vct) == TRUE)
	{
		ft_printf("la ?\n");//DEBUG
		vct_del(&vct);
		vct = NULL;
		free_list(token_list);
		return (FALSE);
	}
	vct_add(vct, ret == N_SIMPLE_QUOTE ? C_SIMPLE_QUOTE : C_QUOTE);
	vct_addcharat(vct, FIRST_CHAR, ret == N_SIMPLE_QUOTE
			? C_SIMPLE_QUOTE : C_QUOTE);
	len = vct_getlen(vct);
	vct_popfrom(input, len - 1);
	if (vct_getcharat(input, FIRST_CHAR) == '=')
	{
		tmp = vct_new();
		tmp = vct_cdup(input, ' ');
		len_tmp = vct_getlen(tmp);
		vct = vct_join(vct, tmp);
		ret_extract = extract_token(token_list, vct_getstr(vct), E_ASSIGN);
		if (ret_extract == FAILURE)
		{
			vct_del(&vct);
			vct = NULL;
			vct_del(&tmp);
			tmp = NULL;
			//free_list(token_list);
			return (FALSE);
		}
		vct_popfrom(input, len_tmp);
	}
	else
	{
		ret_extract = extract_token(token_list, vct_getstr(vct), ret == N_SIMPLE_QUOTE
						? E_SIMPLE_QUOTE : E_QUOTE);
		if (ret_extract == FAILURE)
		{
			vct_del(&vct);
			vct = NULL;
			vct_del(&tmp);
			tmp = NULL;
			free_list(token_list);
			return (FALSE);
		}
	}
	vct_del(&vct);
	vct = NULL;
	return (TRUE);
}
