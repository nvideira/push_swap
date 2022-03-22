/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:42 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/02 21:34:51 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rev_rot(t_targs **a, char stack)
{
	t_targs	*new;
	t_targs	*temp;

	if (stack_size(&(*a)) <= 1)
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
	rev_rot(&(*a), 0);
	rev_rot(&(*b), 0);
	write(1, "rrr\n", 4);
}
