/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:20:52 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/28 19:00:38 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
/*
int main(void)
{
    char *s1;
    char *s2;
    char *result;

    // Teste 1: Concatenar duas strings normais
    s1 = "Hello, ";
    s2 = "World!";
    result = ft_strjoin(s1, s2);
    if (result != NULL)
    {
        printf("Teste 1 - Resultado: %s\n", result);
        free(result); // Liberar a memória alocada
    }
    else
    {
        printf("Teste 1 - Erro ao alocar memória.\n");
    }

    // Teste 2: Concatenar uma string vazia com uma string normal
    s1 = "";
    s2 = "OpenAI!";
    result = ft_strjoin(s1, s2);
    if (result != NULL)
    {
        printf("Teste 2 - Resultado: %s\n", result);
        free(result);
    }
    else
    {
        printf("Teste 2 - Erro ao alocar memória.\n");
    }

    // Teste 3: Concatenar uma string normal com uma string vazia
    s1 = "Hello!";
    s2 = "";
    result = ft_strjoin(s1, s2);
    if (result != NULL)
    {
        printf("Teste 3 - Resultado: %s\n", result);
        free(result);
    }
    else
    {
        printf("Teste 3 - Erro ao alocar memória.\n");
    }

    // Teste 4: Concatenar duas strings vazias
    s1 = "";
    s2 = "";
    result = ft_strjoin(s1, s2);
    if (result != NULL)
    {
        printf("Teste 4 - Resultado: \"%s\"\n", result);
        free(result);
    }
    else
    {
        printf("Teste 4 - Erro ao alocar memória.\n");
    }

    // Teste 5: Concatenar strings com caracteres especiais
    s1 = "Hello\n";
    s2 = "World\t!";
    result = ft_strjoin(s1, s2);
    if (result != NULL)
    {
        printf("Teste 5 - Resultado: %s\n", result);
        free(result);
    }
    else
    {
        printf("Teste 5 - Erro ao alocar memória.\n");
    }

    return 0;
}*/
