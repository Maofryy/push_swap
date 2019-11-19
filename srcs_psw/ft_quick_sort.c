#include "push_swap.h"

static void	bubble_sort(int n, int *tab)
{
	int	index;
	int	tmp;

	index = 1;
	while (index < n)
	{
		if (tab[index] >= tab[index - 1])
			index++;
		else
		{
			tmp = tab[index - 1];
			tab[index - 1] = tab[index];
			tab[index] = tmp;
			if (index > 1)
				index--;
		}
	}
}

static int	find_median_pivot(int n, t_stack *a)
{
	int	*tab;
	int	index;
	int	pivot;

	if (!(tab = (int *)malloc(sizeof(int) * n)))
		return (-1);
	index = 0;
	while (index < n)
	{
		tab[index] = a->data;
	   	a = a->next;
		index++;
	}
	bubble_sort(n, tab);
	pivot = tab[n / 2];
	free(tab);
	return (pivot);
}

static int	part(t_env *e, int value)
{
	if (e->a->data >= value)
	{
    	ft_apply_op(RA, e);
		return (0);
	}
	else
	{
    	ft_apply_op(PB, e);
		return (1);
	}
}

static int	partition(int n, t_env *e, int value)
{
	int		index;
	int		pivot;
	int		stack_size;
	int		rot_count;
	t_op	op;

	index = 0;
	pivot = 0;
	while (n > 0 && !is_gte_value(n, e->a, value))
	{
		part(e, value) ? pivot++ : index++;
		n--;
	}
	stack_size = ft_stack_size(e->a);
	rot_count = (stack_size - index <= stack_size / 2) ? stack_size - index : index;
	op = (stack_size - index <= stack_size / 2) ? RA : RRA;
	index = 0;
	while (index < rot_count)
	{
    	ft_apply_op(op, e);
		index++;
	}
	return (pivot);
}

static int	sort_special_cases(int n, t_env *e)
{
	if (n <= 3)
	{
		ft_three_front_sort(n, e);
		return (1);
	}
	else if (n <= 32)
	{
    	ft_insert_sort(n, e);
		return (1);
	}
	return (0);
}

void ft_quick_sort(int n, t_env *e)
{
  int	value;
	int	pivot;
	int	index;

	if (n < 2 || sort_special_cases(n, e))
		return ;
	value = find_median_pivot(n, e->a);
  	pivot = partition(n, e, value);
  	if (!ft_stack_sorted(e->a, n - pivot))
		ft_quick_sort(n - pivot, e);
  	index = 0;
	while (index < pivot)
	{
    	ft_apply_op(PA, e);
		index++;
	}
	if (!ft_stack_sorted(e->a, pivot))
    ft_quick_sort(pivot, e);
}
