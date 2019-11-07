#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
// #include <limits.h>
# define INT_MIN -2147483648
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
long int			ft_stack_pop(t_stack **s);
long int			ft_stack_pop_beginning(t_stack **s);
int			ft_stack_size(t_stack *s);
void		ft_stack_del(t_stack **alst);
void		ft_free_exit(t_stack *a, t_stack *b);

/*
**	Read args
*/
t_stack 		*ft_read_args(int ac, char **av);
int					ft_is_num(char *str);

/*
**	Operations
*/
typedef enum	e_op
{
	PA, PB,
	SA, SB, SS,
	RA, RB, RR,
	RRA, RRB, RRR
}						t_op;

int			ft_swap(t_stack **s);
int			ft_push(t_stack **a, t_stack **b);
int			ft_rotate(t_stack **s);
int			ft_reverse_rotate(t_stack **s);
int			ft_apply_rot(char *name, t_stack **a, t_stack **b);
void		ft_parse_op(t_stack **a, t_stack **b);

/*
**	Check
*/
void			ft_check(t_stack **a, t_stack **b);
void			ft_free_exit(t_stack *a, t_stack *b);
void			ft_free_only(t_stack *a, t_stack *b);

/*
**	Messages
*/

void ft_error(void);
void ft_ok(void);
void ft_ko(void);

#endif
