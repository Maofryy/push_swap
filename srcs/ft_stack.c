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
