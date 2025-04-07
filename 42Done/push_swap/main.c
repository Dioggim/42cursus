/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:15:59 by dgimenez          #+#    #+#             */
/*   Updated: 2025/03/04 00:50:29 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_struct(t_pushswap *ps)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
}

void	error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	fill_array(int *arr, t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (++i < size)
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	if (argc < 2)
		return (0);
	init_struct(&ps);
	parse_args(&ps, argc, argv);
	if (is_sorted(ps.stack_a))
	{
		free_stack(&ps.stack_a);
		return (0);
	}
	if (ps.size_a <= 5)
		small_sort(&ps);
	else
		turkish_sort(&ps);
	free_stack(&ps.stack_a);
	free_stack(&ps.stack_b);
	return (0);
}
