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

void	ft_stack_push_tail(t_stack **s, int new_data)
{
	t_stack *new;
	t_stack *t;

	t = *s;
	new = ft_stack_new(new_data);
	if (t == NULL)
		*s = new;
	else
	{
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
}

long int	ft_stack_pop_tail(t_stack **s)
{
	int			ret;
	t_stack	*t;

	ret = 0;
	if (*s == NULL)
		return (INT_MIN - 1);
	if ((*s)->next == NULL) {
			ret = (*s)->data;
			free((*s));
			return ((int)ret);
	}
	t = (*s);
	while (t->next->next != NULL) {
			t = t->next;
	}
	ret = t->next->data;
	free(t->next);
	t->next = NULL;
	return ((int)ret);
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

long int	ft_stack_pop(t_stack **s)
{
	int			ret;
	t_stack	*next;

	if (*s == NULL)
		return (INT_MIN - 1);
	next = (*s)->next;
	ret = (*s)->data;
	free(*s);
	*s = next;
	return ((int)ret);
}

int	ft_stack_size(t_stack *s)
{
	t_stack *t;
	int			i;

	t = s;
	if (t == NULL)
		return (0);
	i = 1;
	while (t->next != NULL)
	{
		t = t->next;
		i++;
	}
	return (i);
}

void	ft_stack_del(t_stack **s)
{
	t_stack *t;

	if (*s == NULL)
		return ;
	while ((*s)->next != NULL)
	{
		t = (*s)->next;
		free(*s);
		*s = t;
	}
	free(*s);
}

void	ft_print_stack(t_stack *a, t_stack *b)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = a;
	tmpb = b;
	ft_printf("\na | ");
	while (tmpa)
	{
		ft_printf("% 3d ", tmpa->data);
		tmpa = tmpa->next;
	}
	ft_printf("\nb | ");
	while (tmpb)
	{
		ft_printf("% 3d ", tmpb->data);
		tmpb = tmpb->next;
	}
	ft_putchar('\n');
}

int ft_stack_sorted(t_stack *a, int size)
{
	int inc;

	if (ft_stack_size(a) <= 1)
		return (1);
	if (size < 0)
	{
		size = 2;
		inc = 0;
	}
	else
		inc = -1;

	while (a->next && size > 1)
	{
				if (a->data > a->next->data)
					return(0);
				a = a->next;
				size += inc;
	}
	return (1);
}
