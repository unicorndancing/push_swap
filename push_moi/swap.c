

#include "push_swap.h"

static void	swap(stack_t *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(stack_t **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	do_sb(stack_t **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	do_ss(stack_t **stack_a, stack_t **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
