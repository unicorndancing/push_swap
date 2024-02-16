/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:45:46 by mlapique          #+#    #+#             */
/*   Updated: 2024/02/16 16:01:48 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int Error_code)
{
	if (Error_code == 1)
		write (2, "Error\n", 6);
	else if (Error_code == 2)
		write (2, "Error\n", 6);
	else if (Error_code == 3)
		write (2, "Error\n", 6);
	else if (Error_code == 4)
		write (2, "Error\n", 6);
	return (-1);
}
