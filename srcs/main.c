/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:17:38 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:17:39 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	int	tmp;

	tmp = a->i;
	a = a->next;
	while (a)
	{
		if (a->i < tmp)
			return (0);
		tmp = a->i;
		a = a->next;
	}
	return (1);
}

static void	sort_three(t_stack **a)
{
	int		biggest;
	t_stack	*tmp;

	biggest = (*a)->i;
	tmp = *a;
	while (tmp)
	{
		if (tmp->i > biggest)
			biggest = tmp->i;
		tmp = tmp->next;
	}
	if ((*a)->i == biggest)
		ra(a);
	else if (((*a)->next)->i == biggest)
		rra(a);
	if ((*a)->i > ((*a)->next)->i)
		sa(a);
}

static void	sort(t_stack **a, t_stack **b)
{
	int		size;
	int		i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size && ft_lstsize(*a) > 3)
	{
		if ((*a)->i < size / 2)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	while (ft_lstsize(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (ft_lstsize(*b))
		do_best(a, b);
	if ((*a)->i <= size / 2)
		while ((*a)->i != 1)
			rra(a);
	else
		while ((*a)->i != 1)
			ra(a);
}

static void	push_swap(t_stack **a, t_stack **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (is_sorted(*a))
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc == 1)
		return (write(2, "Error\n", 6), 1);
	a = init(argc, argv);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	push_swap(&a, &b);
	return (ft_lstfree(a), ft_lstfree(b), 0);
}
