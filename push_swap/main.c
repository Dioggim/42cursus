/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:15:59 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 22:16:18 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_struct(t_pushswap *ps)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
}

int main(int argc, char **argv)
{
	t_pushswap ps;

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
