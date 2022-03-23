/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:37:58 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/23 05:04:37 by nvideira         ###   ########.fr       */
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

void	store_args(t_targs **lst, char *arg);
void	lst_add_front(t_targs **lst, t_targs *new);
t_targs	*lst_last(t_targs *lst);
t_targs	*ft_new_node(int content);
int		what_last(t_targs *lst);
void	print_list(t_targs *lst);
void	print_stack(t_targs *lst);
void	print_back(t_targs *lst);
void	swap(t_targs **a, char stack);
void	swap_ss(t_targs **a, t_targs **b);
void	push(t_targs **a, t_targs **b, char direction);
void	rotate(t_targs **a, char stack);
void	rotate_rr(t_targs **a, t_targs **b);
void	rev_rot(t_targs **a, char stack);
void	rev_rot_rrr(t_targs **a, t_targs **b);
int		stack_size(t_targs **stk);
int		check_inputs(char **arg);
void	three_args(t_targs **stack_a);
void	do_four(t_targs **stack_a, t_targs **stack_b);
void	more_args(t_targs **stack_a, t_targs **stack_b);
int		find_small(t_targs **stack);
void	all_but_3(t_targs **stack_a, t_targs **stack_b);
void	different_approach(t_targs **stack_a, t_targs **stack_b);
#endif
