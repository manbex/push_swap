/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:27:09 by mbenicho          #+#    #+#             */
/*   Updated: 2022/11/24 20:27:12 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	int				i;
	struct s_stack	*next;
}	t_stack;

t_stack	*init(int argc, char **argv);
void	ft_lstfree(t_stack *list);
void	ft_lstadd_back(t_stack **list, t_stack *new);
int		ft_lstsize(t_stack *a);
int		ft_superatoi(char *nptr, int *res);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		get_next_line(int fd, char **str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
