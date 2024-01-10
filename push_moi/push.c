

#include "push_swap.h"

static void	push(stack_t **src, stack_t **dest)
{
	stack_t	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}


void	do_pa(stack_t **stack_a, stack_t **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}


void	do_pb(stack_t **stack_a, stack_t **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
