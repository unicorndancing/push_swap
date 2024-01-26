#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack->binary);
		free(stack);
		stack = temp;
	}
	stack = NULL;
}

void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}