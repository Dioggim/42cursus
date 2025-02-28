/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:59:29 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 01:33:18 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** turkish_get_chunk_count
** Ajuste aqui para tentar baixar o total de movimentos.
*/
int turkish_get_chunk_count(int size)
{
    if(size<=100)return(15);
    return(35);
}

/*
** get_pos_in_a
** Encontra posicao (0-based) do valor v em A
*/
/*
static int get_pos_in_a(t_pushswap *ps,int v)
{
    int pos=0; t_node *t=ps->stack_a;
    while(t)
    {
        if(t->value==v)break;
        pos++;
        t=t->next;
    }
    return pos;
}*/

/*
** rotate_a_val
** Roda stack_a ate trazer valor v ao topo (decidindo ra ou rra)
*/
/*
static void rotate_a_val(t_pushswap *ps,int v)
{
    int pos=get_pos_in_a(ps,v);
    int half=ps->size_a/2; int i=0;
    if(pos<=half)while(i<pos){ra(ps);i++;}
    else while(i<(ps->size_a-pos)){rra(ps);i++;}
}*/

/*
** find_insert_pos_b
** Retorna posicao em B (0-based) onde 'val' deve ser inserido
** para manter B ordenada em ordem decrescente (maiores em cima).
*/
static int find_insert_pos_b(t_pushswap *ps,int val)
{
    t_node *tmp=ps->stack_b;int pos=0;
    while(tmp)
    {
        if(tmp->value<val)break;
        pos++;
        tmp=tmp->next;
    }
    return(pos);
}

/*
** push_b_in_order
** Encontra pos em B para inserir 'val' (descrescente), faz rb/rrb e pb.
*/
void push_b_in_order(t_pushswap *ps,int val)
{
    if(!ps->stack_b||!ps->stack_b->next){pb(ps);return;}
    int pos=find_insert_pos_b(ps,val);
    int i=0; int sz=ps->size_b;
    if(pos<=sz/2){while(i<pos){rb(ps);i++;}}
    else{while(i<(sz-pos)){rrb(ps);i++;}}
    pb(ps);
}


