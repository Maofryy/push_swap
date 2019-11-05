#include "push_swap.h"

t_stack *ft_stack_new(int const data)
{
	t_stack *new;

	if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_beginning(t_stack **s, int new_data)
{
	t_stack *new;

	new = ft_stack_new(new_data);
	if (s != NULL && new != NULL)
		(*s)->next = new;
}

void	ft_stack_push(t_stack **s, int new_data)
{
	t_stack *new;

	new = ft_stack_new(new_data);
	if (s != NULL && new != NULL)
	{
		new->next = *s;
		*s = new;
	}
}

int	ft_stack_pop(t_stack **s)
{
	int	ret;
	t_stack *next;

	if (s == NULL)
		return (-1);
	next = (*s)->next;
	ret = (*s)->data;
	free(*s);
	*s = next;
	return (ret);
}
void	ft_print_stack(t_stack *start)
{
	t_stack *t;
	int i;

	t = start;
	i = 0;
	while (t)
	{
		ft_printf("[%d] : % 5d\n", i++, t->data);
		t = t->next;
	}
}
