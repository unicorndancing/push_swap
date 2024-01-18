/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:40:59 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/17 14:14:07 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*result;
	int	i;

	i = 0;
	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	while (i < 11)
	{
		result->value[i] = 2;
		i++;
	}
	result->integer = content;
	result->previous = NULL;
	result->index = 0;
	result->cost = 0;
	result->next = NULL;
	return (result);
}
