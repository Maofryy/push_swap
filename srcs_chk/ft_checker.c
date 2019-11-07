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
	ft_ok();
}
#include <stdio.h>
int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;

	//Parsing numbers // TO REDO
	a = ft_read_args(ac, av);
	if (ft_stack_size(a) <= 1)
	{
		ft_free_only(a, 0);
		ft_ok();
	}
	ft_print_stack(a, b);
	ft_parse_op(&a, &b);
	ft_check(&a, &b);


	ft_printf("i : %ld | d : %d\n", -2147483648, (int)-2147483648);
	return (0);
}
