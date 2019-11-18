#include "push_swap.h"

void ft_get_min_ops(t_env *e)
{
  int n;

  n = ft_stack_size(e->a);
  e->ops = malloc(sizeof(t_op) * n * n * 256);
  // if (n <= 3)
  //   ft_mini_sort(e, n);
  // else if (n <= 10)
  //   ft_insert_sort(n, e);
  // else
  //   ft_quick_sort(n, e);
  //
  //   n = ft_lstsize(ps.lst);
    if (n > 1 && !ft_stack_sorted(e->a, n))
      (n <= 3) ? ft_mini_sort(e, n) : ft_quick_sort(n, e);
    // ft_lstfree(&(ps.tmp));
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
