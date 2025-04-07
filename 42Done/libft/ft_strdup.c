/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:25:41 by dgimenez          #+#    #+#             */
/*   Updated: 2024/09/28 15:44:06 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		len;

	len = ft_strlen(s1);
	dup = (char *)malloc(len + 1);
	i = 0;
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char *original = "minha string original";
	char *duplicada = ft_strdup(original);

	if (duplicada == NULL)
	{
		printf("erro ao duplicar a string\n");
		return (1);
	}
	printf("string duplicada: %s\n", duplicada);
	free(duplicada);
	return (0);
}*/
