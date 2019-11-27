#include "push_swap.h"

int ft_parse_op(t_env *e)
{
  char  *line;
  int   n;

  n = 0;
  while (get_next_line(e->o_fd, &line) > 0)
  {
    if (ft_strlen(line) == 0)
      break ;
    if (ft_apply_rot(line, &e->a, &e->b, e->v_flag) == -1)
    {
      free(line);
      ft_free_error(e->a, e->b);
    }
    n++;
    free(line);
  }
  return (n);
}
