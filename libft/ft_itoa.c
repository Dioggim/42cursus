/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:52 by diogo             #+#    #+#             */
/*   Updated: 2024/09/30 21:47:01 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_allocate_string(int len, int is_negative)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + is_negative + 1));
	if (!str)
		return (NULL);
	str[len + is_negative] = '\0';
	return (str);
}

static void	ft_fill_string(char *str, int n, int len, int is_negative)
{
	int	digit;

	while (len > 0)
	{
		digit = n % 10;
		if (is_negative)
			digit = -digit;
		str[len + is_negative - 1] = digit + '0';
		n /= 10;
		len--;
	}
	if (is_negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		len;
	int		is_negative;
	char	*str;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	len = ft_numlen(n);
	str = ft_allocate_string(len, is_negative);
	if (!str)
		return (NULL);
	ft_fill_string(str, n, len, is_negative);
	return (str);
}

/*
int	main(void)
{
	int		num;
	char	*str;

	num = -12345;
	str = ft_itoa(num);
	if (str)
	{
		printf("O número %d convertido para string é: %s\n", num, str);
		free(str);
	}
	else
	{
		printf("Erro ao converter o número.\n");
	}
	return (0);
}*/

// ft_numlen: Função auxiliar que calcula o número 
// de dígitos do número.
// ft_itoa_helper: Função auxiliar que faz a alocação
// de memória e monta a string resultante.
// ft_itoa: Função principal que converte um inteiro para uma string.
// main: Testa a função ft_itoa com um exemplo, 
// mostrando o resultado e liberando a memória alocada.
