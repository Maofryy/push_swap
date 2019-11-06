#include "push_swap.h"

int	ft_apply_rot(char *name, t_stack **a, t_stack **b)
{
	int	ret;

	ret = -1;
	if (ft_strequ("sa", name) || ft_strequ("ss", name))
		ret = ft_swap(a);
	if (ft_strequ("sb", name) || ft_strequ("ss", name))
		ret = ft_swap(b);
	if (ft_strequ("pa", name))
		ret = ft_push(a, b);
	if (ft_strequ("pb", name))
		ret = ft_push(b, a);
	if (ft_strequ("ra", name) || ft_strequ("rr", name))
		ret = ft_rotate(a);
	if (ft_strequ("rb", name) || ft_strequ("rr", name))
		ret = ft_rotate(b);
	if (ft_strequ("rra", name) || ft_strequ("rrr", name))
		ret = ft_reverse_rotate(a);
	if (ft_strequ("rrb", name) || ft_strequ("rrr", name))
		ret = ft_reverse_rotate(b);
	return (ret);
}

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
      ft_free_exit(*a, *b);
    }
    ft_print_stack(*a, *b);
    free(line);
    // ft_printf("line = %s\n", ft_strtoupper(line));
  }
}
