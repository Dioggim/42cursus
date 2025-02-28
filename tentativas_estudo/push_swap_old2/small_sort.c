/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:46:07 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 13:24:23 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_node *stack)
{
	t_node	*tmp;
	int		smallest;
	int		pos;
	int		i;

	tmp = stack;
	smallest = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	push_smallest(t_node **a, t_node **b)
{
	int	pos;
	int	smallest;

	while (get_stack_size(*a) > 3)
	{
		pos = find_smallest(*a);
		smallest = (*a)->value;
		while ((*a)->value != smallest)
		{
			if (pos < get_stack_size(*a) / 2)
			{
				ra(a);
				printf("Executando ra(), novo topo: %d\n", (*a)->value);
			}
			else
			{
				rra(a);
				printf("Executando rra(), novo topo: %d\n", (*a)->value);
			}
		}
		pb(a, b);
		printf("Executando pb(), movendo %d para B\n", (*b)->value);
	}
}
void	sort_five(t_node **a, t_node **b)
{
	printf("Entrando em sort_five...\n");
	push_smallest(a, b);
	printf("Menores valores empurrados para B...\n");
	sort_three(a);
	printf("sort_three() concluído...\n");
	while (*b)
	{
		printf("Executando pa()...\n");
		pa(a, b);
	}
	printf("sort_five finalizado.\n");
}

void	push_bitwise(t_node **a, t_node **b, int size, int bit, int *count)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
		{
			pb(a, b);
			(*count)++;
		}
		else
			ra(a);
		j++;
	}
}