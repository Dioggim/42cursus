/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:23:17 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 13:11:05 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_node *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
void	process_bit(t_node **a, t_node **b, int size, int bit)
{
	int	count;

	count = 0;
	push_bitwise(a, b, size, bit, &count);
	while (count > 0)
	{
		pa(a, b);
		count--;
	}
}


void	radix_sort(t_node **a, t_node **b, int size)
{
	int	i;
	int	bits;
	int	max;

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
void	choose_sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b, size);
}
void	sort_three(t_node **stack)
{
	int	x;
	int	y;
	int	z;

	x = (*stack)->value;
	y = (*stack)->next->value;
	z = (*stack)->next->next->value;
	if (x > y && y < z && x < z)
		sa(stack);
	else if (x > y && y > z)
	{
		sa(stack);
		rra(stack);
	}
	else if (x > y && y < z)
		ra(stack);
	else if (x < y && y > z && x < z)
	{
		sa(stack);
		ra(stack);
	}
	else if (x < y && y > z)
		rra(stack);
}
