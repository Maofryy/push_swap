#include "push_swap.h"

int ft_swap(t_stack **s)
{
  int   i1;
  int   i2;

  if (ft_stack_size(*s) < 2)
    return (0);
  i1 = ft_stack_pop(s);
  i2 = ft_stack_pop(s);
  if (i1 == INT_MIN || i2 == INT_MIN)
    return (-1);
  ft_stack_push(s, i1);
  ft_stack_push(s, i2);
  // ft_printf("swap\n");
  return (1);
}

int ft_push(t_stack **a, t_stack **b) {
  int i;

  if (b == NULL)
    return (0);
  i = ft_stack_pop(b);
  if (i == INT_MIN)
    return (-1);
  ft_stack_push(a, i);
  // ft_printf("push\n");
  return (1);
}

int ft_rotate(t_stack **s) {
  int i;

  if (ft_stack_size(*s) <= 1)
    return (0);
  i = ft_stack_pop(s);
  if (i == INT_MIN)
    return (-1);
  ft_stack_push_beginning(s, i);
  // ft_printf("rotate\n");
  return (1);
}

int ft_reverse_rotate(t_stack **s) {
  int i;

  if (ft_stack_size(*s) <= 1)
    return (0);
  i = ft_stack_pop_beginning(s);
  if (i == INT_MIN)
    return (-1);
  ft_stack_push(s, i);
  // ft_printf("reverse rotate\n");
  return (1);
}
