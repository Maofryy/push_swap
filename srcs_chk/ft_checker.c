#include "push_swap.h"
#include "libft.h"

void ft_check(t_stack **a, t_stack **b)
{
	t_stack		*t;

	t = *a;
	if (ft_stack_size(*b) != 0)
	{
		ft_free_only(*a, *b);
		ft_ko();
	}
	if (ft_stack_size(*a) <= 1)
		ft_ok();
	while (t->next)
	{
				if (t->data > t->next->data)
				{
					ft_free_only(*a, *b);
					ft_ko();
				}
				t = t->next;
	}
	ft_free_only(*a, *b);
	//Need to free env
	ft_ok();
}

int main(int ac, char **av)
{
	t_env   e;
	int n;

	ft_init_env(&e);
	ft_read_options(ac, av, &e);
	if (e.h_flag || ((ac - e.ac_start <= 0) && !(e.i_flag)) || (e.i_flag && (ac - e.ac_start >= 1)))
  	{
    	ft_chk_print_usage();
    	ft_free_flags(&e);
		exit(EXIT_SUCCESS);
  	}
	if (e.i_flag)
    	e.a = ft_read_input_file(&e);
  	else
    	e.a = ft_read_args(ac, av, e.ac_start);
	if (ft_stack_size(e.a) <= 1)
	{
		ft_free_env_only(&e);
		ft_ok();
	}
	if (e.v_flag)
	{
		ft_putstr("Init stacks :\n");
		ft_print_stack(e.a, e.b);
	}
	e.o_fd = ft_open_input(e.o_flag, e.o_filename, &e);
	n = ft_parse_op(&e);
	ft_close_o(&e);
	ft_printf("%d operations.\n", n);
	ft_check(&e.a, &e.b);
	return (0);
}
