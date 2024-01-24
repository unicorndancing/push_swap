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

void	usable_value(t_stack *stack_a)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;
	int		thesize;

	thesize = get_last_index(stack_a);
	while (thesize > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->integer == INT_MIN && ptr->value == -1)
				ptr->value = 1;
			if (ptr->integer > value && ptr->value == -1)
			{
				value = ptr->integer;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->value = thesize;
		thesize--;
	}
}

void	determine_cost_initial(t_stack *stack_a)
{
	t_stack	*temp;
	int		max_index;
	int		cost;

	cost = 1;
	max_index = get_last_index(stack_a);
	temp = stack_a;
	while (temp)
	{
		if (temp->index < (max_index + 1) / 2)
		{
			temp->cost = cost;
			cost++;
		}
		else if (temp->index == (max_index) / 2)
		{
			temp->cost = cost;
		}
		else
		{
			temp->cost = cost;
			cost--;
		}
		temp = temp->next;
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
	stack_a->cost = 1;
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
	determine_cost_initial(stack_a);
}
