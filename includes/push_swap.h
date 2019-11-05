#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_stack
{
	int		data;
	struct s_stack	*next;
}			t_stack;

t_stack		*ft_stack_new(int const data);

#endif
