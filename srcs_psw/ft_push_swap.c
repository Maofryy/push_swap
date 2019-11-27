#include "push_swap.h"
#include <time.h>
#include <stdio.h>

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
  if (e.o_flag)
    ft_printf("Output written in file : %s\n", e.o_filename);
  ft_close_o(&e);
  ft_free_env(&e);
  return (0);
}
