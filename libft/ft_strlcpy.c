/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:24:01 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/26 12:26:54 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
	// Declaração de strings de origem e destino
	char src1[] = "Olá, 42!";
	char dest1[20];
	char dest2[20];  // Para comparar com a ft_strlcpy
	size_t ret1, ret2;

	// Usando a função original strlcpy
	ret1 = strlcpy(dest1, src1, 20);
	printf("Função original strlcpy:\n");
	printf("Destino: %s\n", dest1);
	printf("Comprimento da origem: %zu\n", ret1);

	// Usando a função personalizada ft_strlcpy
	ret2 = ft_strlcpy(dest2, src1, 20);
	printf("\nFunção personalizada ft_strlcpy:\n");
	printf("Destino: %s\n", dest2);
	printf("Comprimento da origem: %zu\n", ret2);

	// Comparando os resultados
	if (ret1 == ret2 && strcmp(dest1, dest2) == 0)
		printf("\nAs duas funções produzem o mesmo resultado!\n");
	else
		printf("\nAs funções produzem resultados diferentes!\n");

	// Segundo teste com um buffer menor (truncamento)
	char dest3[6];
	char dest4[6];
	ret1 = strlcpy(dest3, src1, 6);
	ret2 = ft_strlcpy(dest4, src1, 6);

	printf("\nTeste com buffer menor (truncamento):\n");

	printf("Função original strlcpy - Destino: %s,
	Comprimento da origem: %zu\n", dest3, ret1);

	printf("Função personalizada ft_strlcpy - Destino:
	%s, Comprimento da origem: %zu\n", dest4, ret2);

	// Comparando os resultados do truncamento
	if (ret1 == ret2 && strcmp(dest3, dest4) == 0)
		printf("\nAs duas funções produzem o mesmo resultado no truncamento!\n");
	else
		printf("\nAs funções produzem resultados diferentes no truncamento!\n");

	return 0;
}*/
