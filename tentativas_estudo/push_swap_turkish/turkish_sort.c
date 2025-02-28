/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:00:48 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/26 01:10:20 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void turkish_sort(t_pushswap *ps)
{
    turkish_compress_values(ps);
    turkish_push_chunks(ps);
    turkish_push_back_to_a(ps);
}

