/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:00 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/22 17:02:55 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_index(t_stack *stack_a)
{
	t_stack	*temp;
	int		max;

	temp = stack_a;
	max = 0;
	while (temp)
	{
		temp = temp->next;
		max++;
	}
	return (max);
}

void	usable_value(t_stack *stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*higher;

	higher = stack;
	temp = stack;
	i = get_last_index(stack);
	while (i > 0)
	{
		while (temp)
		{
			if (temp->integer > higher->integer && temp->value == -1
				|| higher->value != -1)
				higher = temp;
			temp = temp->next;
		}
		higher->value = i - 1;
		i--;
		temp = stack;
		higher = stack;
	}
}

void	ini_stack(char *argv[], t_stack *stack_a)
{
	int		i;
	int		nb;
	t_stack	*new_chain;

	i = 1;
	nb = ft_atoi(argv[0]);
	stack_a->integer = nb;
	stack_a->index = 1;
	stack_a->valuetemp = -1;
	stack_a->next = NULL;
	stack_a->value = -1;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		new_chain = lstnew(nb);
		new_chain->index = i + 1;
		ft_lstadd(stack_a, new_chain);
		i++;
	}
	usable_value(stack_a);
	transform_to_binary(stack_a);
}
