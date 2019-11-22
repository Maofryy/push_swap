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
  int i;

  if (ac < 2)
    ft_ps_print_usage();
  ft_init_env(&e);
  ft_read_options(ac, av, &e);
   if (e.h_flag)
  {
    ft_ps_print_usage();
    ft_free_flags(&e);
  }
  if (e.i_flag)
    e.a = ft_read_input_file(&e);
  else
    e.a = ft_read_args(ac, av, e.ac_start);
  if (ft_stack_size(e.a) <= 1)
        ft_free_env(&e);
  if (!ft_stack_sorted(e.a, -1))
    ft_get_min_ops(&e);
  ft_open_o(&e);
  i = -1;
  while (e.ops && e.ops[++i])
    ft_dprintf(e.o_fd, "%s\n", ft_get_op(e.ops[i]));
  ft_close_o(&e);
  ft_free_env(&e);
  return (0);
}
