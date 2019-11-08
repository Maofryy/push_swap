#include "push_swap.h"

int ft_swap(t_stack **s)
{
  long int   i1;
  long int   i2;

  if (ft_stack_size(*s) < 2)
    return (0);
  i1 = ft_stack_pop(s);
  i2 = ft_stack_pop(s);
    if (i1 == INT_MIN - 1 || i2 == INT_MIN - 1)
    return (-1);
  ft_stack_push(s, (int)i1);
  ft_stack_push(s, (int)i2);
  // ft_printf("swap\n");
  return (1);
}

int ft_push(t_stack **a, t_stack **b) {
  long int i;

  if (b == NULL)
    return (0);
  i = ft_stack_pop(b);
  if (i == INT_MIN - 1)
    return (-1);
  ft_stack_push(a, (int)i);
  // ft_printf("push\n");
  return (1);
}

int ft_rotate(t_stack **s) {
  long int i;

  if (ft_stack_size(*s) <= 1)
    return (0);
  i = ft_stack_pop(s);
  if (i == INT_MIN - 1)
    return (-1);
  ft_stack_push_tail(s, (int)i);
  // ft_printf("rotate\n");
  return (1);
}

int ft_reverse_rotate(t_stack **s) {
  long int i;

  if (ft_stack_size(*s) <= 1)
    return (0);
  i = ft_stack_pop_tail(s);
  if (i == INT_MIN - 1)
    return (-1);
  ft_stack_push(s, (int)i);
  // ft_printf("reverse rotate\n");
  return (1);
}

int	ft_apply_rot(char *name, t_stack **a, t_stack **b)
{
	int	ret;

	ret = -1;
	if (ft_strequ("sa", name) || ft_strequ("ss", name))
		ret = ft_swap(a);
	if (ft_strequ("sb", name) || ft_strequ("ss", name))
		ret = ft_swap(b);
	if (ft_strequ("pa", name))
		ret = ft_push(a, b);
	if (ft_strequ("pb", name))
		ret = ft_push(b, a);
	if (ft_strequ("ra", name) || ft_strequ("rr", name))
		ret = ft_rotate(a);
	if (ft_strequ("rb", name) || ft_strequ("rr", name))
		ret = ft_rotate(b);
	if (ft_strequ("rra", name) || ft_strequ("rrr", name))
		ret = ft_reverse_rotate(a);
	if (ft_strequ("rrb", name) || ft_strequ("rrr", name))
		ret = ft_reverse_rotate(b);
	ft_printf("op : %s\n", name);
	return (ret);
}
