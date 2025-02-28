/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:26:03 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/28 21:43:32 by dgimenez         ###   ########.fr       */
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
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	while (pos-- > 0)
		ra(ps);
	pb(ps);
}

static void	sort_three(t_pushswap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->stack_a->value;
	second = ps->stack_a->next->value;
	third = ps->stack_a->next->next->value;
	if (first > second && second < third && first < third)
		sa(ps);
	else if (first > second && second > third)
	{
		sa(ps);
		rra(ps);
	}
	else if (first > second && second < third && first > third)
		ra(ps);
	else if (first < second && second > third && first < third)
	{
		sa(ps);
		ra(ps);
	}
	else if (first < second && second > third && first > third)
		rra(ps);
}

static void sort_four(t_pushswap *ps)
{
	push_min_to_b(ps);
	sort_three(ps);
	pa(ps);
}

static void sort_five(t_pushswap *ps)
{
	push_min_to_b(ps);
	push_min_to_b(ps);
	sort_three(ps);
	pa(ps);
	pa(ps);
}

void small_sort(t_pushswap *ps)
{
	if (ps->size_a == 2 && !is_sorted(ps->stack_a))
		sa(ps);
	else if (ps->size_a == 3)
		sort_three(ps);
	else if (ps->size_a == 4)
	{
		push_min_to_b(ps);
		sort_three(ps);
		pa(ps);
	}
	else if (ps->size_a == 5)
	{
		push_min_to_b(ps);
		push_min_to_b(ps);
		sort_three(ps);
		pa(ps);
		pa(ps);
	}
}
