/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:20:29 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 00:20:33 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 1) Copia stack_a p/ arr, ordena e reescreve cada node->value com seu rank (0..n-1).
*/
static void compress_values(t_pushswap *ps)
{
	int *arr,i,j; t_node *tmp=ps->stack_a;
	arr=(int*)malloc(sizeof(int)*ps->size_a);
	if(!arr)error_and_exit();
	i=0;while(tmp){arr[i++]=tmp->value;tmp=tmp->next;}
	i=1;while(i<ps->size_a)
	{
		j=i;while(j>0&&arr[j-1]>arr[j])
		{
			int t=arr[j];arr[j]=arr[j-1];arr[j-1]=t;j--;
		}
		i++;
	}
	tmp=ps->stack_a;
	while(tmp)
	{
		j=0;while(arr[j]!=tmp->value)j++;
		tmp->value=j; tmp=tmp->next;
	}
	free(arr);
}

/*
** 2) Encontra quantos bits são necessários p/ representar todos os valores (0..n-1).
**    Ex.: se maior valor for 499, em binario ~9 bits. 
*/
static int get_maxbits(t_pushswap *ps)
{
	int max=0; t_node *tmp=ps->stack_a; 
	int bits=0;
	while(tmp){ if(tmp->value>max)max=tmp->value; tmp=tmp->next;}
	while((max>>bits)!=0)bits++;
	return(bits);
}

/*
** 3) Itera bit a bit (0..maxbits-1). Em cada bit:
**    - Loop size_a vezes: se (valor>>bit)&1 == 0 -> pb, senão ra.
**    - Ao final, todos "0" nesse bit ficam em b; então pa(...) de volta p/ a.
*/
static void lsd_radix(t_pushswap *ps,int maxbits)
{
	int bit=0;int i;int sz;int v;
	while(bit<maxbits)
	{
		i=0;sz=ps->size_a;
		while(i<sz)
		{
			v=ps->stack_a->value;
			if(((v>>bit)&1)==0)pb(ps);
			else ra(ps);
			i++;
		}
		i=0;while(ps->size_b)
		{
			pa(ps);i++;
		}
		bit++;
	}
}

/*
** 4) Função principal
*/
void turkish_sort(t_pushswap *ps)
{
	compress_values(ps);
	lsd_radix(ps, get_maxbits(ps));
}
