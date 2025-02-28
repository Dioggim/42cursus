/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:19:07 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 23:19:35 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Tira o primeiro elemento de stack_b e coloca no topo de stack_a.
** Imprime "pa".
*/
void pa(t_pushswap *ps)
{
	t_node *tmp;

	if (!ps->stack_b)
		return ;
	tmp = ps->stack_b;
	ps->stack_b = ps->stack_b->next;
	tmp->next = ps->stack_a;
	ps->stack_a = tmp;
	ps->size_a++;
	ps->size_b--;
	ft_putendl_fd("pa", 1);
}

/*
** Tira o primeiro elemento de stack_a e coloca no topo de stack_b.
** Imprime "pb".
*/
void pb(t_pushswap *ps)
{
	t_node *tmp;

	if (!ps->stack_a)
		return ;
	tmp = ps->stack_a;
	ps->stack_a = ps->stack_a->next;
	tmp->next = ps->stack_b;
	ps->stack_b = tmp;
	ps->size_a--;
	ps->size_b++;
	ft_putendl_fd("pb", 1);
}
