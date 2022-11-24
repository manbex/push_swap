/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:56 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:20:00 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}
