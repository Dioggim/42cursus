/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:23:17 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/24 18:46:32 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_index(t_node *stack)
{
	int max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static void process_bit(t_node **a, t_node **b, int size, int bit)
{
	int j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

void radix_sort(t_node **a, t_node **b, int size)
{
	int i;
	int bits;
	int max;

	max = get_max_index(*a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	i = 0;
	while (i < bits)
	{
		process_bit(a, b, size, i);
		i++;
	}
}
