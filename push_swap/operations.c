/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:22:34 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/24 18:45:43 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **stack)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
	write(1, "sa\n", 3);
}

void ra(t_node **stack)
{
	t_node *tmp;
	t_node *first;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		*stack = first->next;
		first->next = NULL;
		tmp->next = first;
	}
	write(1, "ra\n", 3);
}

void rra(t_node **stack)
{
	t_node *prev;
	t_node *last;

	if (*stack && (*stack)->next)
	{
		prev = NULL;
		last = *stack;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		if (prev)
			prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	write(1, "rra\n", 4);
}

void pb(t_node **a, t_node **b)
{
	t_node *tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "pb\n", 3);
}

void pa(t_node **a, t_node **b)
{
	t_node *tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	write(1, "pa\n", 3);
}
