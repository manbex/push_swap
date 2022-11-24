/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:18:23 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:18:26 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	find_moves(t_stack *a, t_stack *b, int i, int pos)
{
	t_moves	m;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	m.ra = 0;
	m.rb = 0;
	m.rra = 0;
	m.rrb = 0;
	m.rr = 0;
	m.rrr = 0;
	if ((i <= (size_b / 2) - 1) || i == 0)
		m.rb = i;
	else
		m.rrb = size_b - i;
	if (pos <= (size_a / 2) - 1 || pos == 0)
		m.ra = pos;
	else
		m.rra = size_a - pos;
	merge_rotations(&m);
	return (m);
}

static void	exec_moves(t_stack **a, t_stack **b, t_moves m)
{
	while (m.ra--)
		ra(a);
	while (m.rb--)
		rb(b);
	while (m.rr--)
		rr(a, b);
	while (m.rra--)
		rra(a);
	while (m.rrb--)
		rrb(b);
	while (m.rrr--)
		rrr(a, b);
	pa(a, b);
}

void	do_best(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_moves	best;
	t_moves	temp;
	int		i;
	int		pos;

	tmp = *b;
	i = 0;
	temp.total = INT_MAX;
	while (tmp)
	{
		pos = find_pos(*a, tmp->i);
		if (tmp == *b)
			best = find_moves(*a, *b, i, pos);
		else
			temp = find_moves(*a, *b, i, pos);
		if (temp.total < best.total && tmp != *b)
			best = temp;
		i++;
		tmp = tmp->next;
	}
	exec_moves(a, b, best);
}
