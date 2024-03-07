/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:59:58 by mlapique          #+#    #+#             */
/*   Updated: 2024/03/06 16:10:10 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	way_to_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	int		ndmax;
	t_stack	*tmp;
	int		i;
	int		nb_instack;

	tmp = *stack_b;
	nb_instack = get_last_index(*stack_a) - 1;
	max = get_max_suposed_place(stack_b);
	ndmax = get_ndmax(stack_b);
	i = 1;
	while (tmp->next != NULL)
	{
		if (tmp->suposed_place == max || tmp->suposed_place == ndmax)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < nb_instack / 2)
		return (0);
	else
		return (1);

}

int	get_max_suposed_place(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = -1;
	while (tmp)
	{
		if (tmp->suposed_place > max)
			max = tmp->suposed_place;
		tmp = tmp->next;
	}
	return (max);
}

int	get_ndmax(t_stack **stack)
{
	int		max;
	int		ndmax;
	t_stack	*tmp;

	tmp = *stack;
	max = get_max_suposed_place(stack);
	ndmax = -1;
	while (tmp)
	{
		if (tmp->suposed_place > ndmax && tmp->suposed_place != max)
			ndmax = tmp->suposed_place;
		tmp = tmp->next;
	}
	return (ndmax);
}