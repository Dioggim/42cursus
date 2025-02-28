/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:19:42 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/24 19:05:19 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

int		ft_atoi_push(const char *str, int *error);
t_node	*stack_new(int value);
void	stack_add_back(t_node **stack, t_node *new);
void	free_stack(t_node **stack);
int		check_duplicates(t_node *stack);
int		is_sorted(t_node *stack);
void	index_stack(t_node *stack);
void	radix_sort(t_node **a, t_node **b, int size);

void	sa(t_node **stack);
void	ra(t_node **stack);
void	rra(t_node **stack);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

#endif
