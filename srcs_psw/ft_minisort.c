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

void     ft_minisort(t_stack *a, int n, t_op *ops)
{
	int	max;

	max = ft_stack_max(a, n);
	if (a->data == max)
  {
    ft_rotate(&a);
    *(ops++) = RA;
  }
	else if (a->next->data == max)
	{
    ft_reverse_rotate(&a);
    *(ops++) = RRA;
  }
	else
  {
    ft_swap(&a);
    *(ops++) = SA;
  }
  if (!ft_stack_sorted(a, n))
		ft_minisort(a, n, ops);
  else
    *ops = 0;
}
