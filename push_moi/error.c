/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:45:46 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/22 17:07:55 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int Error_code)
{
	if (Error_code == 1)
		write (2, "error not a number", ft_strlen("error not a number"));
	else if (Error_code == 2)
		write (2, "error not a integer", ft_strlen("error not a integer"));
	else if (Error_code == 3)
		write (2, "error too many number", ft_strlen("error too many number"));
	else if (Error_code == 4)
		write (2, "double detected", ft_strlen("double detected"));
	return (-1);
}