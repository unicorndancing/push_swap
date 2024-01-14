/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/14 14:44:44 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usable_value(char	*arg, t_stack *stack_a)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(arg);
	while (i < 11 - len)
	{
		stack_a->value[i] = '0';
		i++;
	}
	if (arg[0] == '-' || arg[0] == '+')
	{
		stack_a->value[i] = '0';
		if (arg[0] == '-')
			stack_a->value[0] = '-';
	}
}

void	determine_cost(t_stack **stack_a)
{
	while ((*stack_a)->next != NULL)
	{
		(*stack_a)->cost = (*stack_a)->index;
		(*stack_a) = (*stack_a)->next;
	}
}

void	ini_stack(char *argv[], t_stack **stack_a)
{
	int		i;
	int		nb;
	t_stack	*new_chain;

	new_chain = NULL;
	i = 1;
	while (argv[i])
	{
		(*stack_a)->integer = ft_atoi(argv[i]);
		(*stack_a)->index = i;
		usable_value(argv[i], *stack_a);
		*new_chain = *lstnew();
		ft_lstadd(stack_a, new_chain);
		i++;
	}
	determine_cost(stack_a);
}