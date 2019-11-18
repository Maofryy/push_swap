#include "push_swap.h"

static int	can_optimize_rot(const char *curr, const char *next)
{
  if ((ft_strequ(curr, "pa") && ft_strequ(next, "pb"))
		|| (ft_strequ(curr, "pb") && ft_strequ(next, "pa")))
		return (1);
	if ((ft_strequ(curr, "ra") && ft_strequ(next, "rra"))
		|| (ft_strequ(curr, "rra") && ft_strequ(next, "ra")))
		return (1);
	if ((ft_strequ(curr, "rb") && ft_strequ(next, "rrb"))
		|| (ft_strequ(curr, "rrb") && ft_strequ(next, "rb")))
		return (1);
	return (0);
}

t_op *ft_cut_2op_list(t_op *ops, int index, int max)
{
  int  i;

  i = index;
  while (i + 2 < max)
  {
      ops[i] = ops[i + 2];
      i++;
  }
  ops[i] = 0;
  return (ops);
}

void		optimize_couples(t_env *e)
{
  int   index;

	index = 0;
	while (e->ops[index] != 0 && e->ops[index + 1] != 0)
	{
    if (can_optimize_rot(ft_get_op(e->ops[index]), ft_get_op(e->ops[index + 1])))
		{
      e->ops = ft_cut_2op_list(e->ops, index, e->ops_nb);
      e->ops_nb -= 2;
			index = 0;
			continue ;
		}
		index++;
	}
}
