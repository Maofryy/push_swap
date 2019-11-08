#include "push_swap.h"

static void	setup_tab_list(int n, int left, t_stack *a, int *tab, t_op *ops)
{
	int		index;
	t_stack	*curr;

	index = left;
	while (index < n)
	{
		ft_push(&b, &a);
    *(ops++) = PB;
		index++;
	}
	if (!ft_stack_sorted(a, left))
		(ft_stack_size(a) == left)
			? ft_mini_sort(left, ps) : threesort(left, ps);
	index = 0;
	curr = a;
	while (index < left)
	{
		tab[index] = curr->data;
		curr = curr->next;
		index++;
	}
}

static void	create_tab_hole(int n, int *tab, int at)
{
	int	index;

	index = n - 1;
	while (index >= at)
	{
		tab[index + 1] = tab[index];
		index--;
	}
}

static void	rotate_to(int index, t_stack *a)
{
	static int	offset = 0;
	int			tmp;
	int			lst_size;
	int			rot_count;
	t_rot		rot_type;

	tmp = ft_abs(index - offset);
	lst_size = ft_lstsize(ps->lst);
	rot_count = (lst_size - tmp <= lst_size / 2) ? lst_size - tmp : tmp;
	if (offset < index)
		rot_type = (lst_size - tmp <= lst_size / 2) ? RRA : RA;
	else
		rot_type = (lst_size - tmp <= lst_size / 2) ? RA : RRA;
	offset = index;
	index = 0;
	while (index < rot_count)
	{
		ps_rot(rot_type, ps);
		index++;
	}
}

void ft_insertsort(int n, t_env *e)
{
	int	*tab;
	int	left;
	int	index;
	int	j;

	if (!(tab = (int *)ft_memalloc(n * sizeof(int))))
		return ;
	left = ft_min(3, n);
	setup_tab_list(n, left, ps, tab);
	index = left;
	while (index < n)
	{
		j = 0;
		while (j < index && tab[j] < *((int *)(ps->tmp)->content))
			j++;
		create_tab_hole(index, tab, j);
		tab[j] = *((int *)(ps->tmp)->content);
		rotate_to(j, ps);
		ps_rot(PA, ps);
		index++;
	}
	rotate_to(0, ps);
	free(tab);
}
