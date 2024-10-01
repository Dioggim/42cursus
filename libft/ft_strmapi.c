/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 02:16:37 by diogo             #+#    #+#             */
/*   Updated: 2024/10/01 02:20:12 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_default_function(unsigned int i, char c)
{
	return (c + i % 26);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc((strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	char	*original = "abc";
	char	*modified = ft_strmapi(original, ft_default_function);

	if (modified)
	{
		printf("Original: %s\n", original);
		printf("Modified: %s\n", modified);
		free(modified);
	}
	return (0);
}*/