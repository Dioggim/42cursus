/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:20:29 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/28 21:44:35 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 1) Copia stack_a p/ arr, ordena e reescreve cada node->value com seu rank (0..n-1).
*/
static void	compress_values(t_pushswap *ps)
{
	int		*arr;
	int		i;
	int		j;
	t_node	*tmp;

	arr = (int *)malloc(sizeof(int) * ps->size_a);
	if (!arr)
		error_and_exit();
	tmp = ps->stack_a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	i = 0;
	while (++i < ps->size_a)
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			ft_swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
	tmp = ps->stack_a;
	while (tmp)
	{
		j = 0;
		while (arr[j] != tmp->value)
			j++;
		tmp->value = j;
		tmp = tmp->next;
	}
	free(arr);
}

/*
** 2) Encontra quantos bits são necessários p/ representar todos os valores (0..n-1).
**    Ex.: se maior valor for 499, em binario ~9 bits. 
*/
static int	get_maxbits(t_pushswap *ps)
{
	int		max;
	int		bits;
	t_node	*tmp;

	max = 0;
	bits = 0;
	tmp = ps->stack_a;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/*
** 3) Itera bit a bit (0..maxbits-1). Em cada bit:
**    - Loop size_a vezes: se (valor>>bit)&1 == 0 -> pb, senão ra.
**    - Ao final, todos "0" nesse bit ficam em b; então pa(...) de volta p/ a.
*/
static void	lsd_radix(t_pushswap *ps, int maxbits)
{
	int	bit;
	int	i;
	int	size;

	bit = 0;
	while (bit < maxbits)
	{
		i = 0;
		size = ps->size_a;
		while (i < size)
		{
			if (((ps->stack_a->value >> bit) & 1) == 0)
				pb(ps);
			else
				ra(ps);
			i++;
		}
		while (ps->size_b)
			pa(ps);
		bit++;
	}
}

/*
** 4) Função principal
*/
void	turkish_sort(t_pushswap *ps)
{
	compress_values(ps);
	lsd_radix(ps, get_maxbits(ps));
}
