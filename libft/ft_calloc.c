/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:41:53 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/30 23:52:22 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, total_size);
	return (ptr);
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
