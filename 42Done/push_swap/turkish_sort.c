/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:20:29 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/28 22:22:36 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compress_values(t_pushswap *ps)
{
	int		*arr;
	int		j;
	t_node	*tmp;

	arr = (int *)malloc(sizeof(int) * ps->size_a);
	if (!arr)
		error_and_exit();
	fill_array(arr, ps->stack_a);
	sort_array(arr, ps->size_a);
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

static void	lsd_radix(t_pushswap *ps, int maxbits)
{
	int	bit;
	int	i;
	int	size;
	int	num;

	bit = 0;
	while (bit < maxbits)
	{
		i = 0;
		size = ps->size_a;
		while (i < size)
		{
			num = ps->stack_a->value;
			if ((num >> bit) & 1)
				ra(ps);
			else
				pb(ps);
			i++;
		}
		while (ps->size_b)
			pa(ps);
		bit++;
	}
}

void	turkish_sort(t_pushswap *ps)
{
	compress_values(ps);
	lsd_radix(ps, get_maxbits(ps));
}
