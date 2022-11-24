/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:28 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:19:30 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_index(t_stack *a)
{
	t_stack	*lst;
	t_stack	*tmp;
	int		i;
	int		size;

	i = 1;
	size = ft_lstsize(a);
	while (i <= size)
	{
		lst = a;
		tmp = a;
		while (lst)
		{
			if ((lst->n < tmp->n && !lst->i) || tmp->i)
				tmp = lst;
			lst = lst->next;
		}
		tmp->i = i;
		i++;
	}
}

int	check_doubles(t_stack *a)
{
	t_stack	*lst;

	while (a->next)
	{
		lst = a->next;
		while (lst)
		{
			if (lst->n == a->n)
				return (1);
			lst = lst->next;
		}
		a = a->next;
	}
	return (0);
}

t_stack	*init(int argc, char **argv)
{
	int		i;
	int		tmp;
	t_stack	*a;
	t_stack	*new;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		if (ft_superatoi(argv[i], &tmp))
			return (ft_lstfree(a), NULL);
		new = malloc(sizeof(t_stack));
		new->next = NULL;
		if (!new)
			return (ft_lstfree(a), NULL);
		new->n = tmp;
		new->i = 0;
		ft_lstadd_back(&a, new);
		i++;
	}
	if (check_doubles(a))
		return (ft_lstfree(a), NULL);
	ft_index(a);
	return (a);
}
