#include "push_swap.h"

t_stack  *ft_read_args(int ac, char **av)
{
  int i;
  long value;
  t_stack *t;
  t_stack *a;

  i = 0;
  a = NULL;
  while (++i < ac)
  {
    if (ft_strlen(av[i]) > 10)
      ft_free_exit(a, 0);
    if ()
    value = ft_atol(av[i]);
    if (value != (int)value)
      ft_free_exit(a, 0);
    //if not duplicate :
    if (a == NULL)
      a = ft_stack_new((int)value);
    else
    {
      t = a;
      while (t != NULL && t->next != NULL)
      {
        if (t->data == (int)value)
          ft_free_exit(a, 0);
        t = t->next;
      }
      ft_stack_push_beginning(&a, (int)value);
    }
  }
  return (a);
}
