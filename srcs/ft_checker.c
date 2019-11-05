#include "push_swap.h"
#include "libft.h"

void ft_ko(void) {
	ft_printf("KO\n");
	exit(1);
}

void ft_ok(void) {
	ft_printf("OK\n");
	exit(1);
}

void ft_check(t_stack *a, t_stack *b)
{
	t_stack		*t;
	int				i;
	int				m;

	t = a;
	if (ft_stack_size(b) != 0)
		ft_ko();
	if (ft_stack_size(a) <= 1)
		ft_ok();
	i = ft_stack_pop(&t);
	m = ft_stack_pop(&t);
	while (i < m && t != NULL)
	{
		i = m;
		m = ft_stack_pop(&t);
	}
	if (i > m)
		ft_ko();
	else
		ft_ok();
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	int i = 0;
	while (++i < ac)
		ft_stack_push_beginning(&a, ft_atoi(av[i]));

	// ft_printf("size : %d\n", ft_stack_size(a));
	ft_print_stack(a, b);
	ft_swap(&a);
	ft_print_stack(a, b);
	ft_push(&b, &a);
	ft_push(&b, &a);
	ft_push(&b, &a);
	ft_print_stack(a, b);
	ft_rotate(&a);
	ft_rotate(&b);
	ft_print_stack(a, b);
	ft_reverse_rotate(&a);
	ft_reverse_rotate(&b);
	ft_print_stack(a, b);
	ft_swap(&a);
	ft_print_stack(a, b);
	ft_push(&a, &b);
	ft_push(&a, &b);
	ft_push(&a, &b);
	ft_print_stack(a, b);

	ft_check(a, b);


	return (0);
}
