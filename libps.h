/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:37:58 by nvideira          #+#    #+#             */
/*   Updated: 2022/02/24 02:06:33 by nvideira         ###   ########.fr       */
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
void	print_list(t_targs *lst);
void	print_stack(t_targs *lst);
void	print_back(t_targs *lst);
void	swap(t_targs *a);
//void	swap_b(t_targs *b);
//void	swap_ss(t_targs *a, t_targs *b);
void	push(t_targs **a, t_targs **b);
//void	push_b(t_targs **b, t_targs **a);
void	rotate(t_targs **a);
void	rev_rot(t_targs **a);
int		stack_size(t_targs **stk);
int		check_inputs(char **arg);
#endif
