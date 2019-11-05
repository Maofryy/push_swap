#include "push_swap.h"
#include "libft.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stack *a;
	
	a = ft_stack_new(1);
	ft_print_stack(a);
	ft_stack_push(&a, 2);
	ft_print_stack(a);

	return (0);
}
