/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:22:07 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 11:42:18 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert_digits(const char *str, int sign, int *error)
{
	long	res;

	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		res = res * 10 + (*str - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return (res);
}

int	ft_atoi_push(const char *str, int *error)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
	{
		*error = 1;
		return (0);
	}
	res = convert_digits(str, sign, error);
	return ((int)(res * sign));
}

int	check_duplicates(t_node *stack)
{
	t_node	*a;
	t_node	*b;

	a = stack;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->value == b->value)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
