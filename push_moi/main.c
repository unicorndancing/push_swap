/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:54 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/31 14:37:19 by mlapique         ###   ########.fr       */
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

int	is_sorted(t_stack *stacka, t_stack *stackb)
{
	t_stack	*temp;

	temp = stacka;
	if (stackb != NULL)
		return (0);
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
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
	//free_argv(argv);
	//test(stack_a);
	push_swap(&stack_a, &stack_b);
	//test(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
