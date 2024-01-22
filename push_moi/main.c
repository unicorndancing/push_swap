/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:54 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/22 17:15:28 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_dothething(char *argv[])
{
	int		i;
	char	**split;

	i = 1;
	split = argv;
	while (argv[i])
	{
		split[i - 1] = argv[i];
		i++;
	}
	split[i - 1] = NULL;
	return (split);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;

	if (argc < 2)
		return (0);
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		split = ft_dothething(argv);
	if (verif_values_ini(split) == -1)
		return (-1);
	stack_b = malloc(sizeof (t_stack));
	stack_a = malloc(sizeof (t_stack));
	stack_b = NULL;
	ini_stack(split, stack_a);
//	push_swap(stack_a, stack_b);
	test(stack_a);
	return (0);
}

