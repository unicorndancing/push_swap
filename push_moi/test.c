#include "push_swap.h"
#include "stdio.h"

int test(t_stack *stack_a)
{
	t_stack *temp;

	temp = stack_a;
	while (temp)
	{
		printf("binary : %s\nvalue : %d\ninteger :%d\n\n", temp->binary, temp->value, temp->integer);
		temp = temp->next;
	}
	printf("\n\n\n ##################FIN################# \n\n\n\n");
	return (0);
}