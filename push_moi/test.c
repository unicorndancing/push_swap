#include "push_swap.h"
#include "stdio.h"

int test(t_stack *stack_a)
{
	t_stack *temp;

	temp = stack_a;
	while (temp)
	{
		printf("binary : %s\nvalue : %d\ninteger :%d\nindex : %d\ncost :%d\n\n", temp->binary, temp->value, temp->integer, temp->index, temp->cost);
		temp = temp->next;
	}
	return (0);
}