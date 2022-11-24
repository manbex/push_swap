#include "push_swap_bonus.h"

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

static int	do_move(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(a);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b);
	else
		return (1);
	return (0);
}

static int	checker(t_stack **a, t_stack **b)
{
	char	*str;
	int		error;

	error = 0;
	if (get_next_line(0, &str))
		return (write(2, "Error\n", 6), 1);
	if (str)
		if (do_move(a, b, str))
			error = 1;
	while (str)
	{
		free(str);
		if (get_next_line(0, &str))
			return (write(2, "Error2\n", 6), 1);
		if (str)
			if (do_move(a, b, str))
				error = 1;
	}
	if (error == 1)
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(*a))
		return (write(1, "OK\n", 3), 0);
	else
		return (write(1, "KO\n", 3), 0);
	return (0);
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
	checker(&a, &b);
	return (ft_lstfree(a), ft_lstfree(b), 0);
}
