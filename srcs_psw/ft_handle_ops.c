#include "push_swap.h"

void ft_get_min_ops(t_env *e)
{
  int n;

  n = ft_stack_size(e->a);
  e->ops = malloc(sizeof(t_op) * n * n * 256);
  if (n <= 3)
    ft_mini_sort(e, n);
  else if (n <= 16)
    ft_insert_sort(n, e);
  else
    ft_quick_sort(n, e);
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
