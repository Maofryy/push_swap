#include "push_swap.h"

void ft_parse_op(t_stack **a, t_stack **b)
{
  char  *line;

  while (get_next_line(STDIN_FILENO, &line) > 0)
  {
    if (ft_strlen(line) == 0)
      break ;
    if (ft_apply_rot(line, a, b) == -1)
    {
      free(line);
      ft_free_error(*a, *b);
    }
    ft_print_stack(*a, *b);
    free(line);
  }
}
