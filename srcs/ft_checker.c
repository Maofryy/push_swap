#include "push_swap.h"
#include "libft.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stack *a;
	t_stack *b;
	
	a = ft_stack_new(0);
	b = ft_stack_new(0);
	ft_printf("a : %d, b : %d\n", a->data, b->data);
	return (0);
}
