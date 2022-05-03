/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:37:58 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/03 05:10:41 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H
# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct {
	int				content;
	struct s_struct	*next;
	struct s_struct	*prev;
}	t_targs;

/*-----------checks.c------------*/

int		check_inputs(char **arg);

/*--------core_functions.c-------*/

int		largest(t_targs *stack);
int		find_next_smallest(t_targs *stack, int ntb);
int		find_smallest(t_targs *stack);
int		find_small_position(t_targs **stack);
int		stack_size(t_targs **stk);

/*-------llist_functions.c-------*/

void	lst_add_front(t_targs **lst, t_targs *new);
t_targs	*ft_new_node(int content);
t_targs	*lst_last(t_targs *lst);

/*--------push_and_swap.c--------*/

void	push(t_targs **a, t_targs **b, char direction);
void	swap(t_targs **a, char stack);
void	swap_ss(t_targs **a, t_targs **b);

/*-----------rotates.c-----------*/

void	rotate(t_targs **a, char stack);
void	rotate_rr(t_targs **a, t_targs **b);
void	rev_rot(t_targs **a, char stack);
void	rev_rot_rrr(t_targs **a, t_targs **b);

/*--------three_or_four.c--------*/

void	three_args(t_targs **stack_a);
void	do_four(t_targs **stack_a, t_targs **stack_b);

/*------------radix.c------------*/

void	radix(t_targs **s_a, t_targs **s_b, int *org, int size);
void	fill_array(int *org, t_targs *stack);

#endif
