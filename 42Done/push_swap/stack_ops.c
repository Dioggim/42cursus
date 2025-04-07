/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:24:41 by dgimenez          #+#    #+#             */
/*   Updated: 2025/03/03 05:40:58 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error_and_exit();
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_back(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (!*stack)
		*stack = new;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	find_min(t_node *stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_min_pos(t_node *stack, int min)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp && tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}
