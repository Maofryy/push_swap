#include "push_swap.h"

void	ft_three_front_sort(int n, t_env *e)
{
	if (!ft_stack_sorted(e->a, 2))
		ft_apply_op(SA, e);
	else
	{
		ft_apply_op(RA, e);
		ft_apply_op(SA, e);
		ft_apply_op(RRA, e);
	}
	if (!ft_stack_sorted(e->a, n))
		ft_three_front_sort(n, e);
}

static int	ft_stack_max(t_stack *s, int n)
{
	int	max;

	max = s->data;
	while (n > 1)
	{
		s = s->next;
		if (s->data > max)
			max = s->data;
		n--;
	}
	return (max);
}

void     ft_mini_sort(t_env *e, int n)
{
	int	max;

	max = ft_stack_max(e->a, n);
	if (e->a->data == max)
		ft_apply_op(RA, e);
	else if (e->a->next->data == max)
		ft_apply_op(RRA, e);
	else
		ft_apply_op(SA, e);
  if (!ft_stack_sorted(e->a, n))
		ft_mini_sort(e, n);
  else
    e->ops[e->ops_nb] = 0;
}
