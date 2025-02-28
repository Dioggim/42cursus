/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:26:03 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 00:08:24 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_pushswap *ps)
{
	int m, p, i; t_node *t = ps->stack_a;
	m = t->value; p = 0; i = 0;
	while (t)
	{
		if (t->value < m){m = t->value; p = i;}
		t = t->next; i++;
	}
	i = 0;
	while (p <= ps->size_a / 2 && i < p){ra(ps); i++;}
	while (p > ps->size_a / 2 && i < (ps->size_a - p)){rra(ps); i++;}
	pb(ps);
}

static void sort_three(t_pushswap *ps)
{
	int a=ps->stack_a->value,b=ps->stack_a->next->value,c=ps->stack_a->next->next->value;
	if(a>b&&a>c&&b<c)ra(ps);
	else if(a>b&&b>c){ra(ps);sa(ps);}
	else if(a>b&&b<c&&a<c)sa(ps);
	else if(a<b&&b>c&&a>c)rra(ps);
	else if(a<b&&b>c&&a<c){rra(ps);sa(ps);}
}

static void sort_four(t_pushswap *ps)
{
	push_min_to_b(ps);
	sort_three(ps);
	pa(ps);
}

static void sort_five(t_pushswap *ps)
{
	push_min_to_b(ps);
	push_min_to_b(ps);
	sort_three(ps);
	pa(ps);
	pa(ps);
}

void small_sort(t_pushswap *ps)
{
	if(ps->size_a<=2&&!is_sorted(ps->stack_a))sa(ps);
	else if(ps->size_a==3)sort_three(ps);
	else if(ps->size_a==4)sort_four(ps);
	else if(ps->size_a==5)sort_five(ps);
}
