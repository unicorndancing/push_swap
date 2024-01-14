/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:54 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/14 13:57:59 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	// t_stack	*stack_a;
	// t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (verif_values_ini(argv) == -1)
		return (-1);
	// stack_b = NULL;
	// stack_a = NULL;
	// ini_stack(argv, &stack_a);
	// test(stack_a);
	return (0);
}
