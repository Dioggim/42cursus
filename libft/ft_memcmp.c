/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:51:17 by diogo             #+#    #+#             */
/*   Updated: 2024/09/25 14:08:41 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	while (num > 0)
	{
		if ((*p1 - *p2) != 0)
			return (*p1 - *p2);
		p1++;
		p2++;
		num--;
	}
	return (0);
}
/*
int main(void)
{
	char bloco1[] = "abcdef";
	char bloco2[] = "abcdez";
	int resultado = ft_memcmp(bloco1, bloco2, 6);

	if (resultado < 0)
		printf("bloco1 é menor que bloco2\n");
	else if (resultado > 0)
		printf("bloco1 é maior que bloco2\n");
	else
		printf("bloco1 é igual a bloco2\n");

	return 0;
}*/
