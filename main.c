#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (!stack_init(&a, argc, argv))
		error_exit(&a, &b);
	radix_sort(&a, &b);
	free_stack_nodes(&a);
	free_stack_nodes(&b);
	return (0);
}
