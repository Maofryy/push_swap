#include "push_swap.h"

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
  {
    ft_rotate(&e->a);
    e->ops[e->ops_nb++] = RA;
  }
	else if (e->a->next->data == max)
	{
    ft_reverse_rotate(&e->a);
    e->ops[e->ops_nb++] = RRA;
  }
	else
  {
    ft_swap(&e->a);
    e->ops[e->ops_nb++] = SA;
  }
  if (!ft_stack_sorted(e->a, n))
		ft_mini_sort(e, n);
  else
    e->ops[e->ops_nb] = 0;
}
