/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:38 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/31 17:30:30 by mlapique         ###   ########.fr       */
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
