/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:00:18 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 01:41:16 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** turkish_push_back_to_a
** Enquanto B existir, acha maior e roda B ate topo, pa.
*/
void turkish_push_back_to_a(t_pushswap *ps)
{
    while(ps->stack_b)
    {
        t_node *tmp=ps->stack_b; int max=tmp->value;int pos=0;int i=0;int sz=0;
        while(tmp){ if(tmp->value>max){max=tmp->value;pos=i;}tmp=tmp->next;i++;sz++;}
        if(pos<=sz/2){i=0;while(i<pos){rb(ps);i++;}}
        else{i=0;while(i<(sz-pos)){rrb(ps);i++;}}
        pa(ps);
    }
}

/*
** turkish_sort
** 1) Comprime, 2) push_chunks, 3) push_back.
*/
/*
void turkish_sort(t_pushswap *ps)
{
    turkish_compress_values(ps);
    turkish_push_chunks(ps);
    turkish_push_back_to_a(ps);
}*/


