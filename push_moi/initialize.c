/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/19 15:50:41 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usable_value(char	*arg, t_stack *stack_a)
{
	int	len;
	int	i;
	int	j;

	j = 0;
	i = 0;
	len = ft_strlen(arg);
	while (i < 11 - len)
	{
		stack_a->value[i] = '0';
		i++;
	}
	if (arg[0] == '-' || arg[0] == '+')
	{
		stack_a->value[i++] = '0';
		j++;
		if (arg[0] == '-')
			stack_a->value[0] = '-';
	}
	while (arg[j])
	{
		stack_a->value[i] = arg[j];
		i++;
		j++;
	}
}

void	determine_cost(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp)
	{
		temp->cost = temp->index;
		temp = temp->next;
	}
}

void	ini_stack(char *argv[], t_stack *stack_a)
{
	int		i;
	int		nb;
	t_stack	*new_chain;

	i = 2;
	nb = ft_atoi(argv[1]);
	stack_a->previous = NULL;
	stack_a->index = 1;
	stack_a->cost = 1;
	stack_a->next = NULL;
	stack_a->index = 1;
	usable_value(argv[1], stack_a);
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		new_chain = lstnew(nb);
		new_chain->index = i;
		usable_value(argv[i], new_chain);
		ft_lstadd(stack_a, new_chain);
		i++;
	}
	determine_cost(stack_a);
}
