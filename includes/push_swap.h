#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
// #include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
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
	int		ac_start;
	char	*o_filename;
	int		o_fd;
	int		o_flag;
	char	*input_filename;
	int		input_fd;
	int		i_flag;
	int		h_flag;
	int		v_flag;
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
t_stack 		*ft_read_args(int ac, char **av, int ac_start);
int					ft_is_num(char *str);
t_stack			*ft_read_input_file(t_env *e);

/*
**	Operations
*/

int			ft_swap(t_stack **s);
int			ft_push(t_stack **a, t_stack **b);
int			ft_rotate(t_stack **s);
int			ft_reverse_rotate(t_stack **s);
int			ft_apply_rot(char *name, t_stack **a, t_stack **b, int v_flag);
int			ft_parse_op(t_env *e);

char		*ft_get_op(t_op ops);
void    ft_get_min_ops(t_env *e);
int     ft_apply_op(t_op op, t_env *e);


/*
**	Check
*/
void			ft_check(t_stack **a, t_stack **b);
void			ft_free_exit(t_stack *a, t_stack *b);
void			ft_free_only(t_stack *a, t_stack *b);
void			ft_free_error(t_stack *a, t_stack *b);
void 			ft_free_env(t_env *e);
void			ft_free_env_only(t_env *e);
void			ft_free_flags(t_env *e);
void 			ft_init_env(t_env *e);

/*
**	Messages
*/

void ft_error(void);
void ft_ok(void);
void ft_ko(void);
void	ft_ps_print_usage(void);
void	ft_chk_print_usage(void);

/*
**	Sorting
*/
void			ft_mini_sort(t_env *e, int n);
void      ft_insert_sort(int n, t_env *e);
int				is_gte_value(int n, t_stack *s, int value);
void      ft_quick_sort(int n, t_env *e);
void			ft_three_front_sort(int n, t_env *e);

void		  optimize_couples(t_env *e);
t_op      *ft_cut_2op_list(t_op *ops, int index, int max);

/*
**	Options
*/
void	ft_read_options(int ac, char **av, t_env *e);
void    ft_open_o(t_env *e);
void    ft_close_o(t_env *e);
int		ft_open_input(int flag, char *filename, t_env *e);
void    ft_close_input(t_env *e);

#endif
