
#include "push_swap.h"

int	verif_in_order(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_a;
	temp2 = stack_a->next;
	while (temp2)
	{
		if (temp->value >= temp2->value)
			return (1);
		temp = temp->next;
		temp2 = temp2->next;
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
		if (verif_in_order(*stack_a) == 1)
		{
			if ((*stack_a)->binary[i] == '0')
				do_pb(stack_a, stack_b);
			else
			{
				if ((*stack_a)->next != NULL)
					do_ra(stack_a);
			}
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

	if (get_last_index(*stack_a) == 3)	
	{
		do_the_little_sort(stack_a, stack_b);
		return (0);
	}
	i = ft_strlen((*stack_a)->binary) - 1;
	while (i >= 0)
	{
		sortlittlebylittle(stack_a, stack_b, i);
		i--;
	}
	return (1000);
}