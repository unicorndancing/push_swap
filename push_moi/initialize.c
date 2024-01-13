/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/13 15:15:39 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usable_value(char	*arg, t_stack stack_a)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(arg);
	while (i < 11 - len)
	{
		(*stack_a)->value[i] = '0';
		i++;
	}
	if (arg[0] == '-' || arg[0] == '+')
	{
		(*stack_a)->value[i] = '0';
		if (arg[0] == '-')
			(*stack_a)->value[0] = '-';
	}
}

int	determine_cost(t_stack stack_a)
{
	int	cost;
	int	number_of_powers;

	cost = 0;
	while ((*stack_a)->next != NULL)
	{
		(*stack_a)->cost = (*stack_a)->index;
		(*stack_a) = (*stack_a)->next;
	}
}

int	ini_stack(char *argv[], t_stack **stack_a)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		(*stack_a)->interger = ft_atoi(argv[i]);
		(*stack_a)->index = i;
		(*stack_a)->value = usable_value(argv[i]);
		ft_lstadd(stack_a, *stack_a);
	}
	determine_cost(stack_a);
}