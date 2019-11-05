#include "push_swap.h"

void ft_swap(t_stack **s)
{
  int     i1;
  int     i2;

  if (ft_stack_size(*s) < 2)
    return ;
  i1 = ft_stack_pop(s);
  i2 = ft_stack_pop(s);
  ft_stack_push(s, i1);
  ft_stack_push(s, i2);
}

void ft_push(t_stack **a, t_stack **b) {
  int i;

  if (b == NULL)
    return ;
  i = ft_stack_pop(b);
  ft_stack_push(a, i);
}

void ft_rotate(t_stack **s) {
  int i;

  if (ft_stack_size(*s) <= 1)
    return ;
  i = ft_stack_pop(s);
  ft_stack_push_beginning(s, i);
}

void ft_reverse_rotate(t_stack **s) {
  int i;

  if (ft_stack_size(*s) <= 1)
    return ;
  i = ft_stack_pop_beginning(s);
  ft_stack_push(s, i);
}
