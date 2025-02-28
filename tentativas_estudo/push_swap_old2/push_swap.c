/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:20:30 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 12:42:37 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*build_stack(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*new;
	int		i;
	int		error;
	int		num;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		error = 0;
		num = ft_atoi_push(argv[i], &error);
		if (error)
		{
			write(2, "Error\n", 6);
			free_stack(&stack_a);
			return (NULL);
		}
		new = stack_new(num);
		stack_add_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

int	validate_stack(t_node **stack)
{
	if (check_duplicates(*stack))
	{
		write(2, "Error\n", 6);
		free_stack(stack);
		return (-1);
	}
	if (is_sorted(*stack))
	{
		free_stack(stack);
		return (0);
	}
	return (1);
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		valid;

	if (argc < 2)
		return (0);
	stack_a = build_stack(argc, argv);
	if (!stack_a)
		return (1);
	valid = validate_stack(&stack_a);
	if (valid != 1)
	{
		if (valid == 0)
			return (0);
		else
			return (1);
	}
	index_stack(stack_a);
	size = get_stack_size(stack_a);
	stack_b = NULL;
	choose_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	return (0);
}
