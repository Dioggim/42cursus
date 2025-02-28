/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:19:42 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 13:17:33 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

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
void	choose_sort(t_node **a, t_node **b, int size);
void	sort_three(t_node **stack);
void	sort_five(t_node **a, t_node **b);
void	push_smallest(t_node **a, t_node **b);
int		get_stack_size(t_node *stack);
int		find_smallest(t_node *stack);
void	push_bitwise(t_node **a, t_node **b, int size, int bit, int *count);
void	process_bit(t_node **a, t_node **b, int size, int bit);



void	sa(t_node **stack);
void	ra(t_node **stack);
void	rra(t_node **stack);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);


#endif
