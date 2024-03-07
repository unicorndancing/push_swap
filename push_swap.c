/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:49:51 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/06 16:05:17 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_in_order(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_a;
	temp2 = stack_a->next;
	while (temp2)
	{
		if (temp->suposed_place >= temp2->suposed_place)
			return (1);
		temp = temp->next;
		temp2 = temp2->next;
	}
	return (0);
}

void	rotaterr(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	ndmax;

	ndmax = get_ndmax(stack_b);
	max = get_max_suposed_place(stack_b);
	while ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->suposed_place == max)
		{
			do_pa(stack_a, stack_b);
			break ;
		}
		else if ((*stack_b)->suposed_place == ndmax)
		{
			do_pa(stack_a, stack_b);
			do_ra(stack_a);
			break ;
		}
		else
			do_rrb(stack_b);
	}
}

void	rotater(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	ndmax;

	ndmax = get_ndmax(stack_b);
	max = get_max_suposed_place(stack_b);
	while ((*stack_b)->next != NULL)
	{
		if ((*stack_b)->suposed_place == max)
		{
			do_pa(stack_a, stack_b);
			break ;
		}
		else if ((*stack_b)->suposed_place == ndmax)
		{
			do_pa(stack_a, stack_b);
			do_ra(stack_a);
			break ;
		}
		else
			do_rb(stack_b);
	}
}

void	sort_little_by_little(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	which;
	// int ipo = 0;

	if (i == 1)
	{
		while ((*stack_a)->next != NULL)
			do_pb(stack_a, stack_b);
		do_pb(stack_a, stack_b);
	}
	which = way_to_rotate (stack_a, stack_b);
	if (which == 0)
		rotater(stack_a, stack_b);
	else
		rotaterr(stack_a, stack_b);
	if (!(*stack_b)->next)
	{
		// while (is_sorted(*stack_a, *stack_b) == 0 && ipo < 200)
		// {
		// 	do_rra(stack_a);
		// 	ipo++;
		// }
	}
	return ;
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	last_index;

	last_index = get_last_index(*stack_a);
	i = 1;
	if (last_index == 3)
		do_the_little_sort(stack_a, stack_b);
	else if (last_index == 4)
		do_the_less_little_sort(stack_a, stack_b);
	else if (last_index == 5)
		do_the_less_less_little_sort(stack_a, stack_b);
	else
	{
		while (is_sorted(*stack_a, *stack_b) != 1 && i < 5000)
		{
			sort_little_by_little(stack_a, stack_b, i);
			i++;
		}
	}
	return (SUCCES);
}
