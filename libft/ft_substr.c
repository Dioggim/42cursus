/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:48:14 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/28 17:58:46 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i] != '\0')
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
/*
int	main(void)
{
    char *original = "Olá, mundo!";
    char *result;

    // Teste 1: Substring padrão
    result = ft_substr(original, 4, 5);
    printf("Teste 1 - Substring de índice 4, len 5: \"%s\"\n", result);
    free(result);

    // Teste 2: Extraindo do meio da string
    result = ft_substr(original, 7, 3);
    printf("Teste 2 - Substring de índice 7, len 3: \"%s\"\n", result);
    free(result);

    // Teste 3: Índice start maior que o comprimento da string
    result = ft_substr(original, 20, 5);
    printf("Teste 3 - Substring de índice 20, len 5: \"%s\"\n", result);
    free(result);

    // Teste 4: Extraindo desde o começo
    result = ft_substr(original, 0, 3);
    printf("Teste 4 - Substring de índice 0, len 3: \"%s\"\n", result);
    free(result);

    // Teste 5: Extraindo mais do que resta na string
    result = ft_substr(original, 8, 50);
    printf("Teste 5 - Substring de índice 8, len 50: \"%s\"\n", result);
    free(result);

    // Teste 6: Extraindo a string completa
    result = ft_substr(original, 0, 12);
    printf("Teste 6 - Substring de índice 0, len 12: \"%s\"\n", result);
    free(result);

    return (0);
}*/
