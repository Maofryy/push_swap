#include "push_swap.h"

void ft_test_ops(t_env *e)
{
    e->ops = malloc(sizeof(t_op) * 1024);
    ft_swap(&e->a);
    // ft_printf("la ?\n");
    e->ops[e->ops_nb++] = SA;

    // ft_printf("la ?\n");
    ft_rotate(&e->a);
    e->ops[e->ops_nb++] = RA;
    // *(e->ops++) = RA;

    e->ops[e->ops_nb] = 0;
}

int main(int ac, char **av)
{
  t_env e;
  // t_stack *b;
  int i;

  e.a = NULL;
  e.b = NULL;
  e.ops = NULL;
  e.ops_nb = 0;
  e.a = ft_read_args(ac, av);
  // ft_print_stack(e.a, 0);
  if (ft_stack_size(e.a) <= 1)
        ft_free_exit(e.a, e.b);
  // ft_print_stack(e.a, 0);
  if (!ft_stack_sorted(e.a, -1))
    ft_get_min_ops(&e);
    // ft_test_ops(&e);

  // i = 0;
  // ops = malloc(sizeof(t_op) * 4);
  // ops[i++] = PA;
  // ops[i++] = PB;
  // ops[i++] = SA;
  // ops[i] = 0;

  // ft_print_stack(e.a, 0);
  // ft_printf("ops_pos = %d\n", e.ops_nb);
  // optimize_couples(&e);
  i = -1;
  while (e.ops && e.ops[++i])
    ft_printf("%s\n", ft_get_op(e.ops[i]));
  // i = -1;
  // while (e.ops && e.ops[++i])
  //   ft_printf("%s\n", ft_get_op(e.ops[i]));
  // ft_print_stack(a, b);
  // if (ft_ps_issorted(a))
  // ft_printf("%s\n", ft_get_op(ops));
  ft_free_env(&e);
  return (0);
}
