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
  ft_stack_push_beginning(s, (int)i);
  // ft_printf("rotate\n");
  return (1);
}

int ft_reverse_rotate(t_stack **s) {
  long int i;

  if (ft_stack_size(*s) <= 1)
    return (0);
  i = ft_stack_pop_beginning(s);
  if (i == INT_MIN - 1)
    return (-1);
  ft_stack_push(s, (int)i);
  // ft_printf("reverse rotate\n");
  return (1);
}
