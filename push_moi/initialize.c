/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/12 16:22:49 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	what_power(int value)
{
	int	i;

	i = 1;
	if (value > 0)
	{
		while (value > 9)
		{
			value = value / 10;
			i++;
		}
	}
	else
	{
		while (value < -9)
		{
			value = value / 10;
			i++;
		}
	}
	return (i);
}

// int	determine_cost(t_stack stack_a)
// {
// 	int	cost;

// 	cost = 0;
// }

int	ini_stack(char *argv[], t_stack **stack_a)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		(*stack_a)->value = ft_atoi(argv[i]);
		(*stack_a)->index = i;
		(*stack_a)->number_of_numbers = what_power((*stack_a)->value);
		(*stack_a)->next = ft_lstadd_back(**stack_a, *stack_a);
	}
	determine_cost(stack_a);
}