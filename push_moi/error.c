/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:45:46 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/12 15:50:44 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int Error_code)
{
	if (Error_code == 1)
		write (2, "error not a number", 15);
	else if (Error_code == 2)
		write (2, "error not a integer", 15);
	else if (Error_code == 3)
		write (2, "error too many number", 15);
	return (-1);
}