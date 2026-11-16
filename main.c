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
	b= NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (ft_printf("Error\n"), 1);

	i = 1;
	while (i < argc)
	{
		add_node_back(&a, ft_atoi(argv[i]));
		i++;
		
	}
	
	ft_printf("Stack Awith PB\n");
	pb(&a,&b);
	print_stack(a);

	ft_printf("Stack B\n");
	print_stack(b);
	return (0);
}