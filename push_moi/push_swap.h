/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:50 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/22 17:08:08 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "limits.h"
# include "libft/libft.h"

enum e_ErrorCode
{
	NOT_A_NUMBER = 1,
	NOT_AN_INTEGER = 2,
	TOO_MANY_ZERO = 3,
	DOUBLE = 4,
	SUCCES = 1000,
};

typedef struct s_stack
{
	int				integer;
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				index;
	int				cost;
	char			*binary;
}				t_stack;
//test
int		test(t_stack *stack_a);

//verification value
int		verif_values_ini(char *argv[]);

//push_swap
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
t_stack	*ft_lstlas(t_stack *lst);
int		push_swap(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);

//initialization value
int		get_last_index(t_stack *stack_a);
void	transform_to_binary(t_stack *stack_a);
t_stack	*lstnew(int content);
void	ft_lstadd(t_stack *lst, t_stack *new);
void	ini_stack(char *argv[], t_stack *stack_a);

// the errors
int		error(int ErrorCode);

// the swaps mfs
void	do_ss(t_stack *stack_a, t_stack *stack_b);
void	do_sb(t_stack *stack_b);
void	do_sa(t_stack *stack_a);
void	swap(t_stack *stack);

// the rotate mfs
void	rotate(t_stack **stack);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

// the reverserotate mfs 
void	rev_rotate(t_stack *stack);
void	do_rra(t_stack *stack_a);
void	do_rrb(t_stack *stack_b);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);

// the push mfs 
void	push(t_stack **src, t_stack **dest);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

#endif