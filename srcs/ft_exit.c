#include "push_swap.h"

void ft_free_only(t_stack *a, t_stack *b)
{
	ft_stack_del(&a);
	ft_stack_del(&b);
}

void ft_free_exit(t_stack *a, t_stack *b)
{
	ft_stack_del(&a);
	ft_stack_del(&b);
	exit(EXIT_SUCCESS);
}

void ft_free_error(t_stack *a, t_stack *b)
{
	ft_stack_del(&a);
	ft_stack_del(&b);
	ft_error();
}


void ft_ko(void)
{
	ft_printf("KO\n");
	exit(EXIT_SUCCESS);
}

void ft_ok(void)
{
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void ft_error(void)
{
	ft_dprintf(2, "Error\n");
	exit(EXIT_SUCCESS);
}
