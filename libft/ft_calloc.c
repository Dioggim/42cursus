/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:41:53 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/28 14:24:04 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_size;
	void	*pointer;

	total_size = num * size;
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 1, total_size);
	return (pointer);
}
/*
int main (void)
{
	char	*test;

	test = ft_calloc(5,8);
	printf("memoria alocada: %s", test);
	free (test);
	return (0);
}*/
