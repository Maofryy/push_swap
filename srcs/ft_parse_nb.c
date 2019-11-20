#include "push_swap.h"

void ft_init_env(t_env *e)
{
  e->a = NULL;
  e->b = NULL;
  e->ops = NULL;
  e->ops_nb = 0;
  e->ac_start = 1;
  e->o_fd = 1;
  e->input_fd = 0;
  e->o_flag = 0;
  e->i_flag = 0;
  e->h_flag = 0;
  e->v_flag = 0;
}

int ft_is_num(char *str)
{
  char  *s;
  int   ret;

  s = str;
  ret = 0;
  while (*s == ' ')
    s++;
  if (*s == '+' || *s == '-')
    s++;
  while (*s)
  {
    if(*s < '0' || *s > '9')
      return (0);
    else
      ret = 1;
    s++;
  }
  return (ret);
}

static int	ft_is_duplicated(int value, t_stack *s)
{
	while (s != NULL)
	{
    if (s->data == value)
			return (1);
		s = s->next;
	}
	return (0);
}

t_stack  *ft_read_args(int ac, char **av, int ac_start)
{
  int i;
  long value;
  t_stack *t;
  t_stack *a;

  i = ac_start - 1;
  a = NULL;
  while (++i < ac)
  {
    if (ft_strlen(av[i]) > 11 || !(ft_is_num(av[i])))
      ft_free_error(a, 0);
    value = ft_atol(av[i]);
    if (value != (int)value || ft_is_duplicated((int)value, a))
      ft_free_error(a, 0);
    if (a == NULL)
      a = ft_stack_new((int)value);
    else
    {
      t = a;
      while (t != NULL && t->next != NULL)
      {
        if (t->data == (int)value)
          ft_free_error(a, 0);
        t = t->next;
      }
      ft_stack_push_tail(&a, (int)value);
    }
  }
  return (a);
}

static int       ft_tab_length(char **tab)
{
  int i;

  i = 0;
  while (tab[i] != 0)
    i++;
  return (i);
}

t_stack  *ft_read_input_file(t_env *e)
{
    char *line;
    char **tab;
    t_stack *a;

    e->input_fd = ft_open_input(e->i_flag, e->input_filename, e);
    get_next_line(e->input_fd, &line);
    tab = ft_strsplit(line, ' ');
    a = ft_read_args(ft_tab_length(tab), tab, 0);
    ft_close_input(e);
    return (a);
}
