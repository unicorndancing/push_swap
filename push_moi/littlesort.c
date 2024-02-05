/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:38 by mlapique          #+#    #+#             */
/*   Updated: 2024/02/05 17:04:10 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_the_little_sort(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->value == 1)
	{
		if ((*stack_a)->next->value == 0)
			do_sa(stack_a);
		else
			do_rra(stack_a);
	}
	else if ((*stack_a)->value == 0)
	{
		if ((*stack_a)->next->value == 2)
		{
			do_pb(stack_a, stack_b);
			do_ra(stack_a);
			do_pa(stack_a, stack_b);
		}
	}
	else if ((*stack_a)->value == 2)
	{
		do_ra(stack_a);
		if ((*stack_a)->value == 1)
			do_sa(stack_a);
	}
}

void	do_the_less_little_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (verif_in_order(*stack_a) == 1 || (*stack_b)->value < 4)
	{
		if ((*stack_a)->value == 3)
			do_pb(stack_a, stack_b);
		else if ((*stack_b) == NULL)
			do_ra(stack_a);
		else
		{
			do_the_little_sort(stack_a, stack_b);
			do_pa(stack_a, stack_b);
			do_ra(stack_a);
		}
		i++;
		if (i == 50)
			return ;
	}
}

void	do_the_less_less_little_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (verif_in_order(*stack_a) == 1 && get_last_index(*stack_b) < 2)
	{
		if ((*stack_a)->value == 4 || (*stack_a)->value == 3)
		{
			do_pb(stack_a, stack_b);
			i++;
		}
		if (i == 1 && (*stack_a)->next->next->next->value == 3 ||
		(*stack_a)->next->next->next->value == 4 )
			do_rra(stack_a);
		else
			do_ra(stack_a);
	}
	do_the_little_sort(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
		do_rb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
	do_ra(stack_a);
	do_ra(stack_a);
}
