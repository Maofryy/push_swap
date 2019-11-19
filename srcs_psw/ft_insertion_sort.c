#include "push_swap.h"

static void	setup_tab_list(int n, int left, t_env *e, int *tab)
{
	int		index;
	t_stack	*curr;

	index = left - 1;
	while (++index < n)
	{
    if (ft_apply_op(PB, e) == -1)
    {
      free(tab);
      ft_free_error(e->a, e->b);
    }
	}
	if (!ft_stack_sorted(e->a, left))
    (ft_stack_size(e->a) ==left )
			? ft_mini_sort(e, left) : ft_three_front_sort(left, e);
	index = 0;
	curr = e->a;
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

static void	rotate_to(int index, t_env *e)
{
	static int	offset = 0;
	int			tmp;
	int			stack_size;
	int			rot_count;
	t_op		op;

	tmp = ft_abs(index - offset);
	stack_size = ft_stack_size(e->a);
	rot_count = (stack_size - tmp <= stack_size / 2) ? stack_size - tmp : tmp;
	if (offset < index)
		op = (stack_size - tmp <= stack_size / 2) ? RRA : RA;
	else
		op = (stack_size - tmp <= stack_size / 2) ? RA : RRA;
	offset = index;
	index = 0;
	while (index < rot_count)
	{
		ft_apply_op(op, e);
		index++;
	}
}

void ft_insert_sort(int n, t_env *e)
{
	int	*tab;
	int	left;
	int	index;
	int	j;

	// ft_print_stack(e->a, e->b);
	// ft_printf("Using insert sort\n");
	if (!(tab = (int *)ft_memalloc(n * sizeof(int))))
		return ;
	left = ft_min(3, n);
	setup_tab_list(n, left, e, tab);
	index = left;
	while (index < n)
	{
		j = 0;
		while (j < index && tab[j] < e->b->data)
			j++;
		create_tab_hole(index, tab, j);
		tab[j] = e->b->data;
		rotate_to(j, e);
		ft_apply_op(PA, e);
		index++;
	}
	rotate_to(0, e);
	free(tab);
}
