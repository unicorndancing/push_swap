
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

void	thesortstackb(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_b);
	while (nbinstack > 0 && i > 0)
	{
		if ((*stack_b)->binary[i - 1] == '1')
			do_pa(stack_a, stack_b);
		else
		{
			if ((*stack_b)->next != NULL)
				do_rb(stack_b);
		}
		nbinstack--;
	}
}

void	sorttheend(t_stack **stack_a, t_stack **stack_b)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_b);
	while (nbinstack > -1)
	{
		do_pa(stack_a, stack_b);
		nbinstack--;
	}
}

void	sortlittlebylittle(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	nbinstack;

	nbinstack = get_last_index(*stack_a);
	while (nbinstack > 0 && i > 0)
	{
		if ((*stack_a)->binary[i] == '0')
			do_pb(stack_a, stack_b);
		else
		{
			if ((*stack_a)->next != NULL)
				do_ra(stack_a);
		}
		nbinstack--;
	}
	if (i > 1)
		thesortstackb(stack_a, stack_b, i);
	if (i == 0)
		sorttheend(stack_a, stack_b);
	return ;
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = ft_strlen((*stack_a)->binary) - 1;
	while (i >= 0)
	{
		sortlittlebylittle(stack_a, stack_b, i);
		i--;
	}
	return (1000);
}