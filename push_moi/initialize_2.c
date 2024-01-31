/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:19:30 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/31 15:19:33 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_index2(t_stack *stack_a)
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

char	*binary(int nb, int len_nb)
{
	char	*binary;
	char	*result;
	int		i;

	i = 0;
	binary = "01";
	result = malloc (len_nb + 1);
	while (i < len_nb)
	{
		result[i] = '0';
		i++;
	}
	while (nb >= 1)
	{
		result[len_nb - 1] = binary[nb % 2];
		nb = nb / 2;
		len_nb--;
	}
	return (result);
}

void	transform_to_binary(t_stack *stack_a)
{
	int		max;
	t_stack	*temp;
	int		len_nb;

	len_nb = 1;
	max = get_last_index2(stack_a);
	temp = stack_a;
	while (max >= 1)
	{
		max = max / 2;
		len_nb++;
	}
	while (temp)
	{
		temp->binary = malloc (len_nb + 1);
		temp->binary = binary(temp->value, len_nb);
		temp = temp->next;
	}
}
