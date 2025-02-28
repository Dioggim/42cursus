/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgimenez <dgimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:14:54 by dgimenez          #+#    #+#             */
/*   Updated: 2025/02/25 22:46:06 by dgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/*
** Estrutura de nós para a stack.
*/
typedef struct s_node
{
	int             value;
	struct s_node   *next;
}   t_node;

/*
** Estrutura principal contendo stacks e infos úteis.
*/
typedef struct s_pushswap
{
	t_node  *stack_a;
	t_node  *stack_b;
	int     size_a;
	int     size_b;
}   t_pushswap;

/*
** Funções gerais
*/
void    parse_args(t_pushswap *ps, int argc, char **argv);
void    error_and_exit(void);

/*
** Operações básicas
*/
void    sa(t_pushswap *ps);
void    sb(t_pushswap *ps);
void    ss(t_pushswap *ps);
void    pa(t_pushswap *ps);
void    pb(t_pushswap *ps);
void    ra(t_pushswap *ps);
void    rb(t_pushswap *ps);
void    rr(t_pushswap *ps);
void    rra(t_pushswap *ps);
void    rrb(t_pushswap *ps);
void    rrr(t_pushswap *ps);

/*
** Checagens e utilitários
*/
int     is_sorted(t_node *stack);
void    free_stack(t_node **stack);
t_node  *create_new_node(int value);
void    push_front(t_node **stack, t_node *new);
void    push_back(t_node **stack, t_node *new);
int     stack_size(t_node *stack);
long	ft_atol(const char *str);
int		ft_isnumber(const char *str);

/*
** Sorts
*/
void    small_sort(t_pushswap *ps);
void    turkish_sort(t_pushswap *ps); /* chunk-based ou outra abordagem */

/*
** Funções auxiliares (se necessário)
*/
#endif
