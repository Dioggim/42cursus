/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:56:52 by diogo             #+#    #+#             */
/*   Updated: 2024/09/30 18:21:54 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

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

static char	*ft_itoa_helper(int n, int len, int is_negative)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + is_negative + 1));
	if (!str)
		return (NULL);
	str[len + is_negative] = '\0';
	while (len > 0)
	{
		str[len + is_negative - 1] = (is_negative ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
		len--;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int	len;
	int	is_negative;

	is_negative = (n < 0);
	len = ft_numlen(n);
	return (ft_itoa_helper(n, len, is_negative));
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

// ft_numlen: Função auxiliar que calcula o número de dígitos do número.
// ft_itoa_helper: Função auxiliar que faz a alocação de memória e monta a string resultante.
// ft_itoa: Função principal que converte um inteiro para uma string.
// main: Testa a função ft_itoa com um exemplo, mostrando o resultado e liberando a memória alocada.
