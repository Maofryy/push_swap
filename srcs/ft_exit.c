#include "push_swap.h"

void	ft_free_only(t_stack *a, t_stack *b)
{
	ft_stack_del(&a);
	ft_stack_del(&b);
}

void	ft_free_exit(t_stack *a, t_stack *b)
{
	ft_stack_del(&a);
	ft_stack_del(&b);
	exit(EXIT_SUCCESS);
}

void	ft_free_error(t_stack *a, t_stack *b)
{
	ft_stack_del(&a);
	ft_stack_del(&b);
	ft_error();
}

//to test out and implement after insersort is done
void	free_anything(void *arg1, ...)
{
    va_list args;
    void *vp;

    free(arg1);
    va_start(args, arg1);
    while ((vp = va_arg(args, void *)) != 0)
        free(vp);
    va_end(args);
}

void	ft_ko(void)
{
	ft_printf("KO\n");
	exit(EXIT_SUCCESS);
}

void	ft_ok(void)
{
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	ft_dprintf(2, "Error\n");
	exit(EXIT_SUCCESS);
}

void	ft_ps_print_usage(void)
{
	ft_printf("usage : ./push_swap [options] {int list}\n");
	ft_printf("Options:\n");
	ft_printf("\t-h : display this help\n");
	ft_printf("\t-v : activate verbose mode, that prints stacks at each operation\n");
	ft_printf("\t-f [input_filemame] : read int list from a well formated file\n");
	ft_printf("\t-o [output_filemame] : prints to the file passed \n");
	exit(EXIT_SUCCESS);
}

void	ft_chk_print_usage(void)
{
	ft_printf("usage : ./push_swap [options] {int list}\n");
	ft_printf("Options:\n");
	ft_printf("\t-h : display this help\n");
	ft_printf("\t-v : activate verbose mode, that prints stacks at each operation\n");
	ft_printf("\t-f [input_filemame] : read int list from a well formated file\n");
	ft_printf("\t-o [operations_filemame] : read operations from a well formated file\n");
	exit(EXIT_SUCCESS);
}

void	ft_free_flags(t_env *e)
{
	if (e->o_flag)
		free(e->o_filename);
	if (e->i_flag)
		free(e->input_filename);
	exit(EXIT_SUCCESS);
}

void	ft_free_env(t_env *e)
{
	ft_free_only(e->a, e->b);
	free(e->ops);
	ft_free_flags(e);
}
