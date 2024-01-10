
#include "libft/libft.h"

typedef struct stack_s
{
    int value;
    struct stack_s next;
    struct stack_s previous;
    int number_of_numbers;
    int index;
}       stack_t;


// the swaps mfs
void	do_ss(stack_t **stack_a, stack_t **stack_b);
void	do_sb(stack_t **stack_b);
void	do_sa(stack_t **stack_a);
void	swap(stack_t *stack);


// the rotate mfs
static void	rotate(stack_t **stack);
void	do_ra(stack_t **stack_a);
void	do_rb(stack_t **stack b);
void	do_rr(stack_t **stack_a, stack_t **stack_b);

// the reverserotate mfs 
static void	rev_rotate(stack_t **stack);
void	do_rra(stack_t **stack_a);
void	do_rrb(stack_t **stack_b);
void	do_rrr(stack_t **stack_a, stack_t **stack_b);

// the push mfs 
static void	push(stack_t **src, stack_t **dest);
void	do_pa(stack_t **stack_a, stack_t **stack_b);
void	do_pb(stack_t **stack_a, stack_t **stack_b);