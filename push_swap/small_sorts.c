/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:26:03 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/28 22:05:00 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_pushswap *ps)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = ps->stack_a;
	min = tmp->value;
	pos = 0;
	i = -1;
	while (tmp)
	{
		i++;
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
	}
	while (pos-- > 0)
		ra(ps);
	pb(ps);
}

static void	sort_three(t_pushswap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->stack_a->value;
	b = ps->stack_a->next->value;
	c = ps->stack_a->next->next->value;
	if (a > b && b < c && a > c)
		ra(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && b < c && a < c)
		sa(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > c && a > c)
		rra(ps);
}

static void	sort_four(t_pushswap *ps)
{
	push_min_to_b(ps);
	sort_three(ps);
	pa(ps);
}

static void	sort_five(t_pushswap *ps)
{
	int	min;
	int	i;

	while (ps->size_a > 3)
	{
		min = find_min(ps->stack_a);
		i = get_min_pos(ps->stack_a, min);
		while (ps->stack_a->value != min)
		{
			if (i <= ps->size_a / 2)
				ra(ps);
			else
				rra(ps);
		}
		pb(ps);
	}
	sort_three(ps);
	while (ps->size_b)
		pa(ps);
}

void	small_sort(t_pushswap *ps)
{
	if (ps->size_a == 2 && !is_sorted(ps->stack_a))
		sa(ps);
	else if (ps->size_a == 3)
		sort_three(ps);
	else if (ps->size_a == 4)
		sort_four(ps);
	else if (ps->size_a == 5)
		sort_five(ps);
}
