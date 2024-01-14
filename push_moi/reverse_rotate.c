/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:40 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/10 13:02:04 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(stack_t **stack)
{
	stack_t	*tmp;
	stack_t	*feet;
	stack_t	*before_feet;

	feet = gestack_t_bottom(*stack);
	before_feet = gestack_t_before_bottom(*stack);
	tmp = *stack;
	*stack = feet;
	(*stack)->next = tmp;
	before_feet->next = NULL;
}

void	do_rra(stack_t **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	do_rrb(stack_t **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	do_rrr(stack_t **stack_a, stack_t **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}