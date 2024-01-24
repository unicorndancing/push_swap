
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
	while (verif_no_difference(*stack_a, i) == 1)
	{
		if ((*stack_a)->binary[i] == '1')
		{
			do_pb(stack_a, stack_b);
			if ((*stack_b)->next != NULL)
				do_rb(stack_b);
		}
		else
			do_ra(stack_a);
		//test(*stack_a);
	}
	while ((*stack_b))
	{
		do_pa(stack_a, stack_b);
		do_ra(stack_a);
	}
	return ;
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_strlen((*stack_a)->binary) - 1;
	while (is_sorted(*stack_a) == 0)
	{
		sortlittlebylittle(stack_a, stack_b, i);
		i--;
	}
	return (test);
}