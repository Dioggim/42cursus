/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:22:56 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/24 18:46:04 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_count(t_node *stack)
{
	int count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static int *build_array(t_node *stack, int count)
{
	int *arr;
	int i;

	arr = malloc(sizeof(int) * count);
	if (!arr)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < count)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

static void sort_array(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void assign_index(t_node *stack, int *arr, int count)
{
	t_node *tmp;
	int i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < count)
		{
			if (tmp->value == arr[i])
			{
				tmp->index = i;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void index_stack(t_node *stack)
{
	int count;
	int *arr;

	count = get_count(stack);
	arr = build_array(stack, count);
	sort_array(arr, count);
	assign_index(stack, arr, count);
	free(arr);
}
