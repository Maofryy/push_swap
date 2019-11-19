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

static void ft_init_env(t_env *e)
{
  e->a = NULL;
  e->b = NULL;
  e->ops = NULL;
  e->ops_nb = 0;
}
int main(int ac, char **av)
{
  t_env e;
  int i;

  ft_init_env(&e);
  e.a = ft_read_args(ac, av);
  if (ft_stack_size(e.a) <= 1)
        ft_free_exit(e.a, e.b);
  if (!ft_stack_sorted(e.a, -1))
    ft_get_min_ops(&e);

  i = -1;
  while (e.ops && e.ops[++i])
    ft_printf("%s\n", ft_get_op(e.ops[i]));
  ft_free_env(&e);
  return (0);
}
