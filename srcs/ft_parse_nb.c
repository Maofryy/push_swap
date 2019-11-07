#include "push_swap.h"

int ft_is_num(char *str)
{
  char  *s;
  int   ret;

  s = str;
  ret = 0;
  while (*s == ' ')
    s++;
  if (*s == '+' || *s == '-')
    s++;
  while (*s)
  {
    if(*s < '0' || *s > '9')
      return (0);
    else
      ret = 1;
    s++;
  }
  return (ret);
}

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
    if (ft_strlen(av[i]) > 11 || !(ft_is_num(av[i])))
      ft_free_error(a, 0);
    value = ft_atol(av[i]);
    if (value != (int)value)
      ft_free_error(a, 0);
    //if not duplicate :
    if (a == NULL)
      a = ft_stack_new((int)value);
    else
    {
      t = a;
      while (t != NULL && t->next != NULL)
      {
        if (t->data == (int)value)
          ft_free_error(a, 0);
        t = t->next;
      }
      ft_stack_push_beginning(&a, (int)value);
    }
  }
  return (a);
}
