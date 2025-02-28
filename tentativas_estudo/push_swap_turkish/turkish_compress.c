/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_compress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:58:41 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 01:16:47 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** insertion_sort_array
** Ordena o array usando while
*/
static void insertion_sort_array(int *arr, int n)
{
    int i=1;
    while(i<n)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            int tmp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=tmp;
            j--;
        }
        i++;
    }
}

/*
** turkish_compress_values
** Copia stack_a em arr, ordena e reescreve stack_a->value com o índice no array
*/
void turkish_compress_values(t_pushswap *ps)
{
    int *arr;int i;int j; t_node *tmp;
    arr = (int*)malloc(sizeof(int)*ps->size_a);
    if(!arr)error_and_exit();
    i=0; tmp=ps->stack_a;
    while(tmp){arr[i++]=tmp->value;tmp=tmp->next;}
    insertion_sort_array(arr, ps->size_a);
    tmp=ps->stack_a;
    while(tmp)
    {
        j=0;
        while(arr[j]!=tmp->value)j++;
        tmp->value=j;
        tmp=tmp->next;
    }
    free(arr);
}

