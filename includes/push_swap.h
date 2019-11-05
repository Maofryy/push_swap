#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
**	Stack handling
*/

typedef struct		s_stack
{
	int		data;
	struct s_stack	*next;
}			t_stack;

t_stack		*ft_stack_new(int const data);
void		ft_print_stack(t_stack *a, t_stack *b);
void		ft_stack_push(t_stack **s, int new_data);
void		ft_stack_push_beginning(t_stack **s, int new_data);
int			ft_stack_pop(t_stack **s);
int			ft_stack_pop_beginning(t_stack **s);
int			ft_stack_size(t_stack *s);

/*
**	Operations
*/
void			ft_swap(t_stack **s);
void			ft_push(t_stack **a, t_stack **b);
void			ft_rotate(t_stack **s);
void			ft_reverse_rotate(t_stack **s);

/*
**	Check
*/
void			ft_check(t_stack *a, t_stack *b);

#endif
