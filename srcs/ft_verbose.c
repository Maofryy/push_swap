#include "push_swap.h"

char    *ft_charmult(int n, char c)
{
    char    *str;
    int     i;

    i = -1;
    if (n <= 0)
        return ("");
    if ((str = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
        return (NULL);
    while (++i < n)
        str[i] = c;
    str[i] = 0;
    return (str);
}

int     ft_int_digits(int n)
{
    int count;

    count = (n < 0) ? 2 : 1;
    n = (n < 0) ? -n : n;
    while (n >= 10)
    {
        count++;
        n = n / 10;
    }
    return (count);
}

int     ft_stack_max_digits(t_stack *s)
{
    int max;
    

    if (!s)
        return (0);
    max = ft_int_digits(s->data);
    while (s)
    {
        if (ft_int_digits(s->data) > max)
            max = ft_int_digits(s->data);
        s = s->next; 
    }
    return (max);
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	int size_a;
	int size_b;
    int max_a;
    int max_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
    max_a = ft_max(ft_stack_max_digits(a), 1);
    max_b = ft_max(ft_stack_max_digits(b), 1);
	while (size_a > size_b)
	{
		ft_printf(" %s%d|%s\n", ft_charmult(max_a   - ft_int_digits(a->data), ' '), a->data, ft_charmult(max_b, ' '));
		a = a->next;
		size_a--;
	}
	while (size_a < size_b)
	{
		ft_printf(" %s|%s%d\n", ft_charmult(max_a, ' '), ft_charmult(max_b + 1 - ft_int_digits(b->data), ' '), b->data);
		b = b->next;
		size_b--;
	}
	while (a && b)
	{
		ft_printf(" %s%d|%s%d\n", ft_charmult(max_a - ft_int_digits(a->data), ' '), a->data, ft_charmult(max_b - ft_int_digits(b->data), ' '), b->data);
		a = a->next;
		b = b->next;
	}
	ft_printf(" %s|%s\n", ft_charmult(max_a, '_'), ft_charmult(max_b + 1, '_'));
	ft_printf("%sa|%sb \n\n", ft_charmult(max_a, ' '), ft_charmult(max_b - 1, ' '));
}