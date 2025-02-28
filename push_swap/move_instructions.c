/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:25:43 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 22:25:59 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_top(t_node *stack)
{
	int tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void sa(t_pushswap *ps)
{
	swap_top(ps->stack_a);
	ft_putendl_fd("sa", 1);
}

void sb(t_pushswap *ps)
{
	swap_top(ps->stack_b);
	ft_putendl_fd("sb", 1);
}

void ss(t_pushswap *ps)
{
	swap_top(ps->stack_a);
	swap_top(ps->stack_b);
	ft_putendl_fd("ss", 1);
}
