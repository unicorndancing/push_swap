/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:40:59 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/14 14:41:03 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(void *content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	*result = content;
	result->next = NULL;
	return (result);
}