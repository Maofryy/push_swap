#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int		data;
	struct s_stack	*next;
}			t_stack;

t_stack		*ft_stack_new(int const data);
void		ft_print_stack(t_stack *start);
void		ft_stack_push(t_stack **s, int new_data);
void		ft_stack_add_beginning(t_stack **s, int new_data);
int		ft_stack_pop(t_stack **s);

#endif
