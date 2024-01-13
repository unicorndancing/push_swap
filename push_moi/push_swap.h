/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:50 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/13 14:44:08 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum e_ErrorCode : ushort
{
	NOT_A_NUMBER = 1,
	NOT_AN_INTEGER = 2,
	TOO_MANY_ZERO = 3,
};

typedef struct s_stack
{
	int				integer;
	char			value[11];
	struct s_stack	*next;
	struct s_stack	*previous;
	int				index;
	int				cost;
}				t_stack;
//verification value
int		verif_values_ini(char *argv[]);
//initialization value
void	ft_lstadd(t_stack **lst, t_stack *new);
int		ini_stack(char *argv[], t_stack **stack_a);
// the errors
int		error(int ErrorCode);
// the swaps mfs
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	do_sb(t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	swap(t_stack *stack);
// the rotate mfs

void	rotate(t_stack **stack);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

// the reverserotate mfs 
void	rev_rotate(t_stack **stack);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

// the push mfs 
void	push(t_stack **src, t_stack **dest);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
#endif