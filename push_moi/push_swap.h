/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:50 by mlapique          #+#    #+#             */
/*   Updated: 2024/02/19 16:23:50 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "limits.h"
# include "libft/libft.h"

enum e_ErrorCode
{
	NOT_A_NUMBER = -10,
	NOT_AN_INTEGER = -20,
	TOO_MANY_ZERO = -30,
	DOUBLE = -40,
	SUCCES = 1000,
	MALLOC = -50,
};

typedef struct s_stack
{
	int				integer;
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				index;
	int				valuetemp;
	char			*binary;
	int				error;
}				t_stack;

//verification value
int		verif_values_ini(char *argv[]);

// the usefulls
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
t_stack	*ft_lstlas(t_stack *lst);
int		is_sorted(t_stack *stack_a, t_stack *stackb);
int		verif_in_order(t_stack *stack_a);
int		get_last_index(t_stack *stack_a);

//push_swap
void	do_the_little_sort(t_stack **stack_a, t_stack **stack_b);
void	do_the_less_little_sort(t_stack **stack_a, t_stack **stack_b);
void	do_the_less_less_little_sort(t_stack **stack_a, t_stack **stack_b);
int		push_swap(t_stack **stack_a, t_stack **stack_b);

//initialization value
void	free_stack(t_stack *stack);
void	free_argv(char *argv[]);
int		transform_to_binary(t_stack *stack_a);
t_stack	*lstnew(int content);
void	ft_lstadd(t_stack *lst, t_stack *new);
int		ini_stack(char *argv[], t_stack *stack_a);

// the errors
int		error(int ErrorCode);

// the swaps mfs
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	do_sb(t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	swap(t_stack **stack);

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