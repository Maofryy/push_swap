#include "push_swap.h"

int main(int ac, char **av)
{
  t_stack *a;
  // t_stack *b;
  t_op *ops;
  int i;

  a = NULL;
  // b = NULL;

  ops = NULL;
  a = ft_read_args(ac, av);
  if (ft_stack_size(a) <= 1)
        ft_free_exit(a, 0);
  // ft_print_stack(a, 0);
  if (!ft_stack_sorted(a, -1))
    ops = ft_get_min_ops(a);

  // i = 0;
  // ops = malloc(sizeof(t_op) * 4);
  // ops[i++] = PA;
  // ops[i++] = PB;
  // ops[i++] = SA;
  // ops[i] = 0;

  i = -1;
  while (ops && ops[++i])
    ft_printf("%s\n", ft_get_op(ops[i]));

  // ft_print_stack(a, b);
  // if (ft_ps_issorted(a))
  // ft_printf("%s\n", ft_get_op(ops));

  return (0);
}
