/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:21:51 by dgimenez          #+#    #+#             */
/*   Updated: 2025/03/03 05:56:15 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Último de stack_a vira primeiro (reverse rotate A). Imprime "rra".
*/
void	rra(t_pushswap *ps)
{
	t_node	*prev;
	t_node	*last;

	if (!ps->stack_a || !ps->stack_a->next)
		return ;
	prev = NULL;
	last = ps->stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = ps->stack_a;
	ps->stack_a = last;
	ft_putendl_fd("rra", 1);
}

/*
** Último de stack_b vira primeiro (reverse rotate B). Imprime "rrb".
*/
void	rrb(t_pushswap *ps)
{
	t_node	*prev;
	t_node	*last;

	if (!ps->stack_b || !ps->stack_b->next)
		return ;
	prev = NULL;
	last = ps->stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = ps->stack_b;
	ps->stack_b = last;
	ft_putendl_fd("rrb", 1);
}

/*
** Função auxiliar para realizar reverse rotate em uma stack
*/
static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/*
** Executa rra e rrb ao mesmo tempo. Imprime "rrr".
*/
void	rrr(t_pushswap *ps)
{
	if (!ps)
		return ;
	reverse_rotate_stack(&ps->stack_a);
	reverse_rotate_stack(&ps->stack_b);
	ft_putendl_fd("rrr", 1);
}
