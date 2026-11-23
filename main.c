#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
    t_bench         bench;

	a = NULL;
	b = NULL;
    init_bench(&bench);
    detect_bench_flag(argc, argv, &bench);
	if (!stack_init(&a, argc, argv))
		error_exit(&a, &b);
    if (bench.enabled)
        bench.disorder = calc_disorder_pct(a);
	algo_adaptive(&a, &b);
    if (bench.enabled)
        print_bench(&bench, "Adaptive", "O(n log n)");
	free_stack_nodes(&a);
	free_stack_nodes(&b);
	return (0);
}
