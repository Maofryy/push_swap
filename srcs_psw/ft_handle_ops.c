#include "push_swap.h"

void ft_get_min_ops(t_env *e)
{
  int n;

  n = ft_stack_size(e->a);
  e->ops = malloc(sizeof(t_op) * (n * n * 256 + 1));
  if (n <= 3)
    ft_mini_sort(e, n);
  else
    ft_quick_sort(n, e);
  optimize_couples(e);
}

int		is_gte_value(int n, t_stack *s, int value)
{
	while (n > 0)
	{
		if (s->data < value)
			return (0);
		s = s->next;
		n--;
	}
	return (1);
}
