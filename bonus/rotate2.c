#include "push_swap_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while ((tmp->next)->next)
		tmp = tmp->next;
	(tmp->next)->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	rra(t_stack **a)
{
	if ((*a)->next)
		reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	if ((*b)->next)
		reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a)->next)
		reverse_rotate(a);
	if ((*b)->next)
		reverse_rotate(b);
}
