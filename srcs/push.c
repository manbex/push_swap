/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:17:45 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:17:46 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	write(1, "pb\n", 3);
}
