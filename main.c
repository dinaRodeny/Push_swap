#include "push_swap.h"

void	print_stack(t_stack_node *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		ft_printf("Node %d: %d\n", i, stack->value);
		stack = stack->next;
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;
	a = NULL;
	b = NULL;
	if (argc == 1)
		error_exit(&a, &b);
	i = 1;
	while (i < argc)
	{
		char	**values;
		int		j;

		values = ft_split(argv[i], ' ');
		if (!values || !values[0])
		{
			if (values)
				free(values);
			error_exit(&a, &b);
		}
		j = 0;
		while (values[j])
		{
			add_node_back(&a, ft_atoi(values[j]));
			j++;
		}
		j = 0;
		while (values[j])
			free(values[j++]);
		free(values);
		i++;
	}
	if (is_duplicate_number(a))
		error_exit(&a, &b);

	print_stack(a);
	radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
