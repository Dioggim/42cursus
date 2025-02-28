/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_push_chunks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:17:46 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 01:34:15 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** turkish_push_chunks
** 1) Divide [0..size-1] em chunk_count
** 2) Para cada valor do chunk, rotate_a_val + push_b_in_order
*/
void turkish_push_chunks(t_pushswap *ps)
{
    int s=ps->size_a;
    int cc=turkish_get_chunk_count(s);
    int chunk_sz=s/cc+(s%cc!=0);
    int c=0;
    while(c<cc)
    {
        int start=c*chunk_sz;
        int end=start+chunk_sz-1;if(end>=s)end=s-1;
        int val=start;
        while(val<=end&&val<s)
        {
            /*rotate_a_val(ps,val);*/
            if(ps->stack_a->value==val)push_b_in_order(ps,val);
            val++;
        }
        c++;
    }
}
