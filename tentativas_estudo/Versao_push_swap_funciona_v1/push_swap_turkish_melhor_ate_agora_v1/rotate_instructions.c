/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:20:26 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 23:21:18 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Move o primeiro elemento de stack_a para o final de stack_a. Imprime "ra".
*/
void ra(t_pushswap *ps)
{
	t_node *top;

	if (!ps->stack_a || !ps->stack_a->next)
		return ;
	top = ps->stack_a;
	ps->stack_a = ps->stack_a->next;
	top->next = NULL;
	push_back(&ps->stack_a, top);
	ft_putendl_fd("ra", 1);
}

/*
** Move o primeiro elemento de stack_b para o final de stack_b. Imprime "rb".
*/
void rb(t_pushswap *ps)
{
	t_node *top;

	if (!ps->stack_b || !ps->stack_b->next)
		return ;
	top = ps->stack_b;
	ps->stack_b = ps->stack_b->next;
	top->next = NULL;
	push_back(&ps->stack_b, top);
	ft_putendl_fd("rb", 1);
}

/*
** ra e rb ao mesmo tempo. Imprime "rr".
*/
void rr(t_pushswap *ps)
{
	t_node *tmp;

	/* ra */
	if (ps->stack_a && ps->stack_a->next)
	{
		tmp = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		tmp->next = NULL;
		push_back(&ps->stack_a, tmp);
	}
	/* rb */
	if (ps->stack_b && ps->stack_b->next)
	{
		tmp = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		tmp->next = NULL;
		push_back(&ps->stack_b, tmp);
	}
	ft_putendl_fd("rr", 1);
}
