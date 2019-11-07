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

t_op *ft_get_min_ops(t_stack *a)
{
  int n;
  t_op *ops;

  n = ft_stack_size(a);
  ops = malloc(sizeof(t_op) * 10);
  if (n <= 3)
    ft_minisort(a, n, ops);
  else
    return (NULL);
  return (ops);
}
