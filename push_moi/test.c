#include "push_swap.h"
#include "stdio.h"

int test(t_stack *stack_a)
{
	while (stack_a)
	{
		printf("%s\n%d\n%d\n%d", stack_a->value, stack_a->integer, stack_a->index, stack_a->cost);
		stack_a = stack_a->next;
	}
	return (0);
}