#include "push_swap.h"

void ft_get_min_ops(t_env *e)
{
  int n;

  n = ft_stack_size(e->a);
  e->ops = malloc(sizeof(t_op) * 1024);
  if (n <= 3)
    ft_mini_sort(e, n);
  else if (n <= 32)
    ft_insert_sort(n, e);
}
