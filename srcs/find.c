#include "push_swap.h"

static int	find_min(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		n;

	tmp = a;
	i = 0;
	j = -1;
	n = INT_MAX;
	while (tmp)
	{
		if (tmp->i < n)
		{
			j = i;
			n = tmp->i;
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}

int	find_pos(t_stack *a, int value)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		n;

	tmp = a;
	i = 0;
	j = -1;
	n = INT_MAX;
	while (tmp)
	{
		if (tmp->i > value && tmp->i < n)
		{
			j = i;
			n = tmp->i;
		}
		i++;
		tmp = tmp->next;
	}
	if (j == -1)
		j = find_min(a);
	return (j);
}

void	merge_rotations(t_moves *m)
{
	if (m->ra && m->rb && m->ra > m->rb)
	{
		m->rr = m->rb;
		m->ra = m->ra - m->rb;
		m->rb = 0;
	}
	else if (m->ra && m->rb)
	{
		m->rr = m->ra;
		m->rb = m->rb - m->ra;
		m->ra = 0;
	}
	else if (m->rra && m->rrb && m->rra > m->rrb)
	{
		m->rrr = m->rrb;
		m->rra = m->rra - m->rrb;
		m->rrb = 0;
	}
	else if (m->rra && m->rrb)
	{
		m->rrr = m->rra;
		m->rrb = m->rrb - m->rra;
		m->rra = 0;
	}
	m->total = m->ra + m->rb + m->rr + m->rra + m->rrb + m->rrr;
}
