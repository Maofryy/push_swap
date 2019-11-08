#include "push_swap.h"

char *ft_get_op(t_op ops)
{
	if (ops == 1)
		return ("pa");
	else if (ops == 2)
		return ("pb");
	else if (ops == 3)
		return ("sa");
	else if (ops == 4)
		return ("sb");
	else if (ops == 5)
		return ("ss");
	else if (ops == 6)
		return ("ra");
	else if (ops == 7)
		return ("rb");
	else if (ops == 8)
		return ("rr");
	else if (ops == 9)
		return ("rra");
	else if (ops == 10)
		return ("rrb");
	else if (ops == 11)
		return ("rrr");
	else
		return (NULL);
}

void ft_get_min_ops(t_env *e)
{
  int n;

  n = ft_stack_size(e->a);
  e->ops = malloc(sizeof(t_op) * 1024);
  if (n <= 3)
    ft_mini_sort(e, n);
  // else if (n <= 32)
    // ft_insertion_sort(n, e);
}
