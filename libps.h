/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:37:58 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/03 04:42:24 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H
# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_struct {
	int				content;
	struct s_struct	*next;
	struct s_struct	*prev;
}	t_targs;

int		check_inputs(char **arg);
void	lst_add_front(t_targs **lst, t_targs *new);
t_targs	*ft_new_node(int content);
t_targs	*lst_last(t_targs *lst);
void	three_args(t_targs **stack_a);
void	do_four(t_targs **stack_a, t_targs **stack_b);
void	radix(t_targs **s_a, t_targs **s_b, int *org, int size);
void	swap(t_targs **a, char stack);
void	swap_ss(t_targs **a, t_targs **b);
void	push(t_targs **a, t_targs **b, char direction);
void	rotate(t_targs **a, char stack);
void	rotate_rr(t_targs **a, t_targs **b);
void	rev_rot(t_targs **a, char stack);
void	rev_rot_rrr(t_targs **a, t_targs **b);
int		find_small_position(t_targs **stack);
int		find_smallest(t_targs *stack);
void	print_list(t_targs *lst);
void	print_stack(t_targs *lst);
void	print_back(t_targs *lst);
int		largest(t_targs *stack);
int		stack_size(t_targs **stk);
void	fill_array(int *org, t_targs *stack);
int		find_next_smallest(t_targs *stack, int ntb);

#endif
