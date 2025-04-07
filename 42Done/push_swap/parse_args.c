/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:17:00 by dgimenez          #+#    #+#             */
/*   Updated: 2025/03/03 05:23:42 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *str)
{
	long	val;

	val = ft_atol(str);
	if (val < -2147483648L || val > 2147483647L)
		return (0);
	return (1);
}

static void	check_duplicate(t_pushswap *ps, int value)
{
	t_node	*curr;

	curr = ps->stack_a;
	while (curr)
	{
		if (curr->value == value)
			error_and_exit();
		curr = curr->next;
	}
}

void	parse_args(t_pushswap *ps, int argc, char **argv)
{
	int		i;
	int		val;
	t_node	*new;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || !is_int(argv[i]))
			error_and_exit();
		val = ft_atoi(argv[i]);
		check_duplicate(ps, val);
		new = create_new_node(val);
		push_back(&ps->stack_a, new);
		ps->size_a++;
		i++;
	}
}
