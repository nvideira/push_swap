/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:33 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/03 04:05:30 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate(t_targs **a, char stack)
{
	t_targs	*new;
	t_targs	*end;

	if (stack_size(a) <= 1)
		return ;
	new = *a;
	end = lst_last(*a);
	*a = (*a)->next;
	(*a)->prev = NULL;
	new->prev = end;
	end->next = new;
	new->next = NULL;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write(1, "rb\n", 3);
}

void	rotate_rr(t_targs **a, t_targs **b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	rev_rot(t_targs **a, char stack)
{
	t_targs	*new;
	t_targs	*temp;

	if (stack_size(a) <= 1)
		return ;
	new = lst_last(*a);
	temp = new;
	new = new->prev;
	new->next = NULL;
	temp->next = *a;
	temp->prev = NULL;
	(*a)->prev = temp;
	*a = (*a)->prev;
	if (stack == 'a')
		write(1, "rra\n", 4);
	else if (stack == 'b')
		write(1, "rrb\n", 4);
}

void	rev_rot_rrr(t_targs **a, t_targs **b)
{
	rev_rot(a, 0);
	rev_rot(b, 0);
	write(1, "rrr\n", 4);
}
