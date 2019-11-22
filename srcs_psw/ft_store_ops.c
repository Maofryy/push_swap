#include "push_swap.h"

void   ft_store_op(t_op op, t_env *e)
{
  if (ft_apply_rot(ft_get_op(op), e->a, e->b, e->v_flag) == -1)
    ft_free_env(e);
  *(ops++) = op;
}
