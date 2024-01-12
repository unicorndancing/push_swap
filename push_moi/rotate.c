/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:43 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/10 13:01:49 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(stack_t **stack)
{
	stack_t	*tmp;
	stack_t	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = gestack_t_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(stack_t **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	do_rb(stack_t **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	do_rr(stack_t **stack_a, stack_t **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
