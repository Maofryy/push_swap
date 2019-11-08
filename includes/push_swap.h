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

typedef enum	e_op
{
	NUL,
	PA, PB,
	SA, SB, SS,
	RA, RB, RR,
	RRA, RRB, RRR
}						t_op;

typedef struct		s_env
{
	t_stack *a;
	t_stack *b;
	t_op		*ops;
	int     ops_nb;
}									t_env;

t_stack		*ft_stack_new(int const data);
void		ft_print_stack(t_stack *a, t_stack *b);
void		ft_stack_push(t_stack **s, int new_data);
void		ft_stack_push_tail(t_stack **s, int new_data);
long int			ft_stack_pop(t_stack **s);
long int			ft_stack_pop_tail(t_stack **s);
int			ft_stack_size(t_stack *s);
void		ft_stack_del(t_stack **alst);
void		ft_free_exit(t_stack *a, t_stack *b);
int			ft_stack_sorted(t_stack *a, int size);

/*
**	Read args
*/
t_stack 		*ft_read_args(int ac, char **av);
int					ft_is_num(char *str);

/*
**	Operations
*/

int			ft_swap(t_stack **s);
int			ft_push(t_stack **a, t_stack **b);
int			ft_rotate(t_stack **s);
int			ft_reverse_rotate(t_stack **s);
int			ft_apply_rot(char *name, t_stack **a, t_stack **b);
void		ft_parse_op(t_stack **a, t_stack **b);

char		*ft_get_op(t_op ops);
void    ft_get_min_ops(t_env *a);


/*
**	Check
*/
void			ft_check(t_stack **a, t_stack **b);
void			ft_free_exit(t_stack *a, t_stack *b);
void			ft_free_only(t_stack *a, t_stack *b);
void			ft_free_error(t_stack *a, t_stack *b);
void 			ft_free_env(t_env *e);

/*
**	Messages
*/

void ft_error(void);
void ft_ok(void);
void ft_ko(void);

/*
**	Sorting
*/
void			ft_mini_sort(t_env *e, int n);
void      ft_insertsort(int n, t_env *e);
#endif
