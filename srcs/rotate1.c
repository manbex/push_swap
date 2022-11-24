#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	(tmp->next)->next = NULL;
}

void	ra(t_stack **a)
{	
	if ((*a)->next)
		rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if ((*b)->next)
		rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a)->next)
		rotate(a);
	if ((*b)->next)
		rotate(b);
	write(1, "rr\n", 3);
}
