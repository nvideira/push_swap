/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:27:33 by nvideira          #+#    #+#             */
/*   Updated: 2022/03/06 17:35:35 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	rotate(t_targs **a, char stack)
{
	t_targs	*new;
	t_targs	*end;

	if (stack_size(&(*a)) <= 1)
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
	rotate(&(*a), 0);
	rotate(&(*b), 0);
	write(1, "rr\n", 3);
}
