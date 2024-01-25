
#include "push_swap.h"

int	verif_no_difference(t_stack *stack_a, int i)
{
	t_stack	*temp;

	temp = stack_a->next;
	while (temp)
	{
		if (stack_a->binary[i] != temp->binary[i])
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sortlittlebylittle(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_a);
	while (nbinstack > 0)
	{
		if ((*stack_a)->binary[i] == '0')
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
		nbinstack--;
	}
	while ((*stack_b))
	{
		do_pa(stack_a, stack_b);
	}
	return ;
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_strlen((*stack_a)->binary) - 1;
	while (is_sorted(*stack_a) == 0 && i != -1)
	{
		sortlittlebylittle(stack_a, stack_b, i);
		i--;
	}
	return (1);
}