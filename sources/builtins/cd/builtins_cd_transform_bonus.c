#include "minishell_bonus.h"

static int	find_last_root(char *pwd)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (pwd[i] != '\0')
	{
		if (pwd[i] == C_ROOT)
			count = i;
		i++;
	}
	return (count);
}

static int	find_last_root_dot(char *pwd)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (pwd[i] != '\0')
	{
		if (ft_strnequ(DOTDOT, pwd + i, 2) == TRUE)
			count++;
		i++;
	}
	return (count);
}

static void	cut_root(t_vector *new_dir, size_t count_root)
{
	size_t i;

	i = 0;
	while (i < count_root)
	{
		vct_cutfrom(new_dir, 3);
		i++;
	}
	if (vct_getcharat(new_dir, vct_getlen(new_dir) - 1) == C_ROOT)
		vct_cut(new_dir);
}

static void	cut_dir(t_vector *new_dir, size_t count_root)
{
	size_t i;
	size_t last_root;

	i = 0;
	while (i < count_root)
	{
		last_root = find_last_root(vct_getstr(new_dir));
		vct_cutfrom(new_dir, vct_getlen(new_dir) - last_root);
		i++;
	}
}

void		transform_new_dir(t_vector *new_dir, char *pwd, char *dir_denied)
{
	size_t		count_root;
	t_vector	*vct_denied;
	t_vector	*real_vct_denied;

	vct_denied = vct_new();
	real_vct_denied = vct_new();
	vct_addstr(vct_denied, dir_denied);
	while (vct_getlen(vct_denied) > 0)
	{
		while (vct_getfirstchar(vct_denied) == C_ROOT &&
				vct_getcharat(vct_denied, 1) == C_ROOT)
			vct_pop(vct_denied);
		vct_add(real_vct_denied, vct_getfirstchar(vct_denied));
		vct_pop(vct_denied);
	}
	vct_addstr(new_dir, pwd);
	vct_add(new_dir, C_ROOT);
	vct_addstr(new_dir, vct_getstr(real_vct_denied));
	vct_del(&real_vct_denied);
	vct_del(&vct_denied);
	count_root = find_last_root_dot(vct_getstr(new_dir));
	cut_root(new_dir, count_root);
	cut_dir(new_dir, count_root);
}
