/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:18:15 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:18:17 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if ((*b)->next)
		reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a)->next)
		reverse_rotate(a);
	if ((*b)->next)
		reverse_rotate(b);
	write(1, "rrr\n", 4);
}
