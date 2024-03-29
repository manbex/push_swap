/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_superatoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:17:17 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:17:20 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_superatoi(char *nptr, int *res)
{
	long	n;
	int		sign;
	int		nb;

	n = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (n * 10);
		if (nb / 10 != n)
			return (1);
		n = (long)nb + *nptr - '0';
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (1);
		nptr++;
	}
	if (*nptr)
		return (1);
	*res = n * sign;
	return (0);
}
